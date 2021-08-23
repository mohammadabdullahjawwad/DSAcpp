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

void insertAtHead(node*& head, int data) {
    if(head == NULL) {
        head = new node(data);
        return;
    }
    node* n = new node(data);
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

void buildList(node*& head) { // This may or may not accept the head
    int data;
    cin >> data;
    while(data != -1) {
    // while(cin >> data) { // When taking input from a file
        insertAtHead(head, data);
        // insertAtTail(head, data);
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

int main() {
    OJ;
    FIO;
    node* head = NULL;
    buildList(head);
    print(head);
    return 0;
}