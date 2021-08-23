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
    node*n = new node(data); // We use dynamic allocation so that is object persists even after this function is removed from stack. It is because we need it even after this function is removed from stack!
    n->next = head;
    head = n;
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
    return;
}

void insertInMiddle(node*& head, int data, int p) {
    // Insert at the Start
    if((head == NULL) || (p == 0)) {
        insertAtHead(head, data);
    }
    // Insert at the End
    else if(p > length(head)) {
        insertAtTail(head, data);
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

bool searchRecursive(node* head, int key) {
    if(head == NULL) {
        return false;
    }
    if(head->data == key) {
        return true;
    }
    return searchRecursive(head->next, key);
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

void print(node* head) {
    // node*temp = head;
    while(head != NULL) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << endl;
}

void deleteAtHead(node*& head) {
    if(head == NULL) {
        return;
    }
    node* temp = head;
    head = head->next;
    delete temp;
    return;
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
        delete temp;
        prev->next = temp->next;
        return;
    }
}

void buildList(node*& head) { // This may or may not accept the head
    int data;
    cin >> data;
    while(data != -1) {
        insertAtTail(head, data);
        cin >> data;
    }
}

istream& operator>>(istream& is, node*& head) {
    buildList(head);
    return is;
}

ostream& operator<<(ostream& os, node* head) {
    print(head);
    return os;
}

int main() {
    OJ;
    FIO;
    node* head = NULL;
    node* head2 = NULL;
    cin >> head >> head2;
    cout << head << head2;
    return 0;
}