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
    OJ;
    FIO;
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
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}