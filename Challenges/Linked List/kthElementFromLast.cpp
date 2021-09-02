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
    OJ;
    FIO;
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