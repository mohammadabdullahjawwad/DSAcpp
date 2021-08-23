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
    node*n = new node(data);
    n->next = head;
    head = n;
}

void buildList(node*& head) { // This may or may not accept the head
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

void reverseIteratively(node *&head) {
    node *C = head;
    node *P = NULL;
    node *N;
    while(C != NULL) {
        N = C->next; // Save the next node
        C->next = P;
        P = C;
        C = N;
    }
    head = P;
}

node* reverseRecursively(node *head) {
    // Base Case - LL with one or zero nodes is already sorted
    if(head->next == NULL || head == NULL) {
        return head;
    }
    // Recursive Case
    node *smallHead = reverseRecursively(head->next);
    head->next->next = head;
    head->next = NULL;
    return smallHead;
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
    cin >> head;
    cout << head;
    // reverseIteratively(head);
    // cout << head;
    head = reverseRecursively(head);
    cout << head;
    return 0;
}