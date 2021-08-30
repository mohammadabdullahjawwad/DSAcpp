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
    cout << "NULL";
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
    cout << head << endl;
    node* mid = midpoint(head);
    cout << mid->data << endl;
    return 0;
}