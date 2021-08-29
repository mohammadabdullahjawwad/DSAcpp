#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

class node {
public:
    int data;
    node* next;

    // Constructor
    node(int d) {
        data = d;
        next = NULL;
    }
};

// class linkedList {
//     node*head;
//     node*tail;
// public:
//     linkedList() {
//         head = NULL;
//         tail = NULL;
//     }
// }

int length(node* head) {
    int len = 0;
    while(head != NULL) {
        head = head->next;
        len++;
    }
    return len;
}

// Passing a pointer variable by reference
void insertAtHead(node*& head, int data) {
    if(head == NULL) {
        head = new node(data);
        return;
    }
    node* n = new node(data); // We use dynamic allocation so that this object persists even after this function is removed from stack. It is because we need it even after this function is removed from stack!
    n->next = head; // We can equivalently write (*n).next = head;
    head = n;
}

void print(node* head) {
    while(head != NULL) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << endl;
}

void insertAtTail(node*& head, int data) {
    if(head == NULL) {
        head = new node(data);
        return;
    }
    node* tail = head;
    while(tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = new node(data);
}

void insertInMiddle(node*& head, int data, int p) {
    // Insert at the Start
    if((head == NULL) || (p == 0)) {
        insertAtHead(head, data);
        return;
    }
    // Insert at the End
    if(p > length(head)) {
        insertAtTail(head, data);
        return;
    }
    // Insert in the middle
    int jump = 1;
    node* temp = head;
    // Take p-1 jumps
    while(jump <= p-1) {
        temp = temp->next;
        jump++;
    }
    node* n = new node(data);
    n->next = temp->next;
    temp->next = n;
}

void deleteAtHead(node*& head) {
    if(head == NULL) {
        return;
    }
    node* temp = head->next;
    delete head;
    head = temp;
}
void deleteAtTail(node*& head) {
    node* prev = NULL;
    node *temp = head;
    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    delete temp;
    return;
}

void deleteInMiddle(node *& head, int p) {
    if((head == NULL) || (p == 0)) {
        deleteAtHead(head);
    }
    else if(p > length(head)) {
        deleteAtTail(head);
    }
    else {
        int jump = 1;
        node* prev = NULL;
        node* temp = head;
        while(jump <= p-1) {
            prev =  temp;
            temp = temp->next;
            jump++;
        }
        prev->next = temp->next;
        delete temp;
    }
}

bool searchIterative(node* head, int key) {
    while(head != NULL) {
        if(head->data == key) {
            return true;
        }
        head = head->next;
    }
    return false;
}

bool searchRecursive(node* head, int key) {
    if(head == NULL) {
        return false;
    }
    if(head->data == key) {
        return true;
    }
    return searchRecursive(head->next, key);
}

int main() {
    OJ;
    FIO;
    node* head = NULL;
    insertAtHead(head, 5);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);
    print(head);
    insertInMiddle(head, 4, 3);
    insertAtTail(head, 7);
    print(head);
    deleteAtHead(head);
    // deleteAtTail(head);
    // deleteInMiddle(head, 2);
    print(head);
    int key;
    cin >> key;
    if(searchRecursive(head, key)) {
        cout << "Present!" << endl;
    }
    else {
        cout << "Not present!" << endl;
    }
    // if(searchIterative(head, 4)) {
    //     cout << "Present!" << endl;
    // }
    // else {
    //     cout << "Not present!" << endl;
    // }
    return 0;
}