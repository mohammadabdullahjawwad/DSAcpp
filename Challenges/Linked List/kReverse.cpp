#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    // Constructor
    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtEnd(node*& head, int data) {
    if(head == NULL) {
        head = new node(data);
        return;
    }
    node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new node(data); 
}

node* kReverse(node* head, int k) {
    node* c = head;
    node* p = NULL;
    node* n = NULL;
    int count = 0;
    while(c != NULL && count < k) {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
        count++;
    }
    if(n != NULL) {
        head->next = kReverse(n, k);
    }
    return p; // This is the new head
}

void print(node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    node* head = NULL;
    int n, k;
    cin >> n >> k;
    while(n--) {
        int data;
        cin >> data;
        insertAtEnd(head, data);
    }
    head = kReverse(head, k);
    print(head);
    return 0;
}
