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
    head = merge(head, head2);
    cout << head;
    return 0;
}