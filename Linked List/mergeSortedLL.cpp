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
    node(int d) {
        data = d;
        next = NULL;
    }
};

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

void buildList(node*& head) {
    int data;
    cin >> data;
    while(data != -1) {
        insertAtTail(head, data);
        cin >> data;
    }
}

void print(node* head) {
    while(head != NULL) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL";
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

int main() {
    OJ;
    FIO;
    node* head = NULL;
    node* head2 = NULL;
    cin >> head >> head2;
    cout << head << endl << head2 << endl;
    head = merge(head, head2);
    cout << head << endl;
    return 0;
}