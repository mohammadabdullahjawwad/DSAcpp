// This is not complete. We have to provide input and then check for the program. I don't know how to provide input (loop)!

#include <iostream>
using namespace std;

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
        cout << head->data << "->";
        head = head->next;
    }
    cout << endl;
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

bool detectCycle(node* head) {
    node* slow = head;
    node* fast = head;
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) {
            return true;
        }
    }
    return false;
}

node* removeCycle(node* head) {
    node* slow = head;
    node* fast = head;
    while(fast != slow) {
        fast = fast->next->next;
        slow = slow->next;
    }
    slow = head;
    node* previous;
    while(fast != slow) {
        previous = fast;
        fast = fast->next;
        slow = slow->next;
    }
    previous->next = NULL;
    return head;
}

int main() {
    node* head = NULL;
    cin >> head;
    if(detectCycle(head) == true) {
        cout << removeCycle(head);
    }
    cout << head;
    return 0;
}