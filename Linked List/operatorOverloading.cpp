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

void print(node* head) {
    // node*temp = head;
    while(head != NULL) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL";
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
    cout << head << endl << head2;
    return 0;
}