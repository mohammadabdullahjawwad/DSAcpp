#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int data) {
        this->data = data;
        next = NULL;
    }
};

void insertAtEnd(node*& head, int data) {
    if(head == NULL) {
        head = new node(data);
        return;
    }
    node*temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new node(data);
}

void evenAfterOdd(node*& head) {
    if(head == NULL || head->next == NULL) {
        return;
    }
    node* odd = NULL;
    node* even = NULL;
    node* temp = head;
    while(temp != NULL) {
        if(temp->data%2 == 0) {
            insertAtEnd(even, temp->data);
        }
        else {
            insertAtEnd(odd, temp->data);
        }
        temp = temp->next;
    }
    temp = odd;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = even;
    head = odd;
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
    int n;
    cin >> n;
    while(n--) {
        int data;
        cin >> data;
        insertAtEnd(head, data);
    }
    evenAfterOdd(head);
    print(head);
    return 0;
}