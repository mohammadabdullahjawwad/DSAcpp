#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

node* insert(node* root, int data) {
    // Base Case
    if(root == NULL) {
        return new node(data);
    }
    // Recursive Case
    if(data <= root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

node* build() {
    int data;
    cin >> data;
    node* root = NULL;
    while(data != -1) { // It is ordered and hence only one -1. This marks the end of input
        root = insert(root, data);
        cin >> data;
    }
    return root;
}

bool search(node * root, int data) {
    if(root == NULL) {
        return false;
    }
    if(root->data == data) {
        return true;
    }
    if(data < root->data) {
        return search(root->left, data);
    }
    else {
        return search(root->right, data);
    }
}

int main() {
    node* root = build();
    int data;
    cin >> data;
    cout << search(root, data) << endl;
    return 0;
}