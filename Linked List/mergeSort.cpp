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

int length(node* head) {
    int len = 0;
    while(head != NULL) {
        head = head->next;
        len++;
    }
    return len;
}

void insertAtHead(node*& head, int data) {
    node*n = new node(data);
    n->next = head;
    head = n;
}

void buildList(node*& head) {
    int data;
    cin >> data;
    while(data != -1) {
        insertAtHead(head, data);
        cin >> data;
    }
}

void print(node* head) {
    while(head != NULL) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << endl;
}

istream& operator>>(istream& is, node*& head) {
    buildList(head);
    return is;
}

ostream& operator<<(ostream& os, node* head) {
    print(head);
    return os;
}

node* merge(node* a, node* b) {
    if(a == NULL) {
        return b;
    }
    if(b == NULL) {
        return a;
    }
    node* c;
    if(a->data < b->data) {
        c = a;
        c->next = merge(a->next, b);
    }
    else {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}

node* midpoint(node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    node* slow = head;
    node* fast = head->next;
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node* mergeSort(node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    node* mid = midpoint(head);
    node* a = head;
    node* b = mid->next;
    mid->next = NULL; // This splits the Linked List into 2 Linked Lists
    a = mergeSort(a);
    b = mergeSort(b);
    node* c = merge(a, b);
    return c;
}

int main() {
    OJ;
    FIO;
    node* head = NULL;
    cin >> head;
    cout << head;
    head = mergeSort(head);
    cout << head;
    return 0;
}