#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
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

void kAppend(node*& head, int k, int n) {
	if(n == 0 || k == 0) {
		return;
	}
    node* prev = head;
    node* curr = head->next;
    for(int i=1; i<n-k; i++) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;
    node* temp = curr;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head;
    head = curr;
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
    int i = n;
    while(i--) {
        int data;
        cin >> data;
        insertAtEnd(head, data);
    }
    int k;
    cin >> k;
	k = k % n; // Since k can be greater than n
    kAppend(head, k, n);
    print(head);
    return 0;
}