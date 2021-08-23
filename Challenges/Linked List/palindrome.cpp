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

void insertAtTail(node*& head, int data) {
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

void insertAtHead(node*& head, int data) {
    node* temp = new node(data);
    temp-> next = head;
    head = temp;
}

bool palindrome(node* head, node* headr) {
    while(head != NULL) {
        if(head->data != headr->data) {
            return false;
        }
        head = head->next;
        headr = headr->next;
    }
    return true;
}

int main() {
    node* head = NULL;
    node* headr = NULL;
    int n;
    cin >> n;
    while(n--) {
        int data;
        cin >> data;
        insertAtTail(head, data);
        insertAtHead(headr, data);
    }
    int res;
    if(palindrome(head, headr)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
    return 0;
}