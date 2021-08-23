#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int d) {
        data = d;
        next = NULL;
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

int kthFromLast(node*& head, int k) {
    node* slow = head;
    node* fast = head;
    while(k--) {
        fast = fast->next;
    }
    while(fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow->data;
}

int main() {
    node* head = NULL;
    int data;
    cin >> data;
    while(data != -1) {
        insertAtEnd(head, data);
        cin >> data;
    }
    int k;
    cin >> k;
    cout << kthFromLast(head, k) << endl;
    return 0;
}