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

void insert(node*& head, int data) {
    if(!head) {
        head = new node(data);
        return;
    }
    node* temp = head;
    while(temp->next) {
        temp = temp->next;
    }
    temp->next = new node(data);
}

void insertionSort(node* head) {
    node* sorted = head;
    node* unsorted = head->next;
    unsorted = unsorted->next;
    while(unsorted) {
        sorted = head;
        while(sorted != unsorted) {
            if(sorted->data > unsorted->data) {
                swap(unsorted->data, sorted->data);
            }
            else {
                sorted = sorted->next;
            }
        }
        unsorted = unsorted->next;
    }
}

void print(node* head) {
    while(head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    OJ;
    FIO;
    node* head = NULL;
    int n;
    cin >> n;
    while(n--) {
        int data;
        cin >> data;
        insert(head, data);
    }
    insertionSort(head);
    print(head);
    return 0;
}