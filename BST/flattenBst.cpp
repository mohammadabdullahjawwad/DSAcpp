#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* insert(node* root, int data) {
    if(root == NULL) {
        return new node(data);
    }
    if(data <= root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

node* create() {
    int data;
    cin >> data;
    node* root = NULL;
    while(data != -1) {
        root = insert(root, data);
        cin >> data;
    }
    return root;
}

class linkedList {
public:
    node* head;
    node* tail;
};

linkedList flatten(node* root) {
    linkedList l;
    if(root == NULL) {
        l.head = NULL;
        l.tail = NULL;
        return l;
    }
    // Case 1 - Leaf node
    if(root->left == NULL && root->right == NULL){
        l.head = root;
        l.tail = root;
        return l;
    }
    // Case 2 - LST is not NULL and RST is NULL
    if(root->right == NULL) {
        linkedList left = flatten(root->left);
        left.tail->right = root;
        l.head = left.head;
        l.tail = root;
        return l;
    }
    // Case 3 - RST is not NULL and LST is NULL
    if(root->left == NULL) {
        linkedList right = flatten(root->right);
        root->right = right.head;
        l.head = root;
        l.tail = right.tail;
        return l;
    }
    // Case 4 - LST ans RST are both not NULL. Postorder traversal
    linkedList left = flatten(root->left);
    linkedList right = flatten(root->right);
    left.tail->right = root;
    root->right = right.head;
    l.head = left.head;
    l.tail = right.tail;
    return l;
}

void print(node* head) {
    while(head != NULL) {
        cout << head->data << "->";
        head = head->right;
    }
    cout << "NULL\n";
}

int main() {
    node* root = create();
    linkedList ans = flatten(root);
    print(ans.head);
    return 0;
}