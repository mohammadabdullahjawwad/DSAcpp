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

void insert(node*& head, int data) {
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

int intersection(node* head1, node* head2, int diff) {
    while(diff--) {
        head1 = head1->next;
    }
    while(head1 != NULL || head2 != NULL) {
        if(head1->data == head2->data) {
            return head1->data;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return -1;
}

int main() {
    node* head1 = NULL;
    node* head2 = NULL;
    int n1;
    cin >> n1;
    int i = n1;
    while(i--) {
        int data;
        cin >> data;
        insert(head1, data);
    }
    int n2;
    cin >> n2;
    i = n2;
    while(i--) {
        int data;
        cin >> data;
        insert(head2, data);
    }
    int diff = 0;
    if(n1 > n2) {
        diff = n1 - n2;
        cout << intersection(head1, head2, diff) << endl;
    }
    else {
        diff = n2 - n1;
        cout << intersection(head2, head1, diff) << endl;
    }
    return 0;
}