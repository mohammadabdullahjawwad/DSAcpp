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

void print(node* head) {
    // node*temp = head;
    while(head != NULL) {
        cout << head->data << " ";
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

int main() {
    OJ;
    FIO;
    int t;
    cin >> t;
    while(t--) {
        node* head1 = NULL;
        node* head2 = NULL;
        int n1, n2;
        cin >> n1;
        while(n1--) {
            int data;
            cin >> data;
            insertAtTail(head1, data);
        }
        cin >> n2;
        while(n2--) {
            int data;
            cin >> data;
            insertAtTail(head2, data);
        }
        node* head = merge(head1, head2);
        print(head);
        delete head1;
        delete head2;
    }
    return 0;
}