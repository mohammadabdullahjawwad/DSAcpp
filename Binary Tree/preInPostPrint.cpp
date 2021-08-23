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

node* buildTree() {
    int d;
    cin >> d;
    // Base Case - reached the end of the tree
    if(d == -1) {
        return NULL;
    }
    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

// Preorder Print - Root--L--R
void printPreOrder(node* root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

// Inorder Print - L--Root--R
void printInOrder(node* root) {
    if(root == NULL) {
        return;
    }
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

// Postorder Print - L--R--Root
void printPostOrder(node* root) {
    if(root == NULL) {
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

int main() {
    node* root = buildTree();
    printPreOrder(root);
    cout << endl;
    printInOrder(root);
    cout << endl;
    printPostOrder(root);
    cout << endl;
    return 0;
}