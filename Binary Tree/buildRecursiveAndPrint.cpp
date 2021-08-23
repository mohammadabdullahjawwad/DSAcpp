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
void print(node* root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << " ";
    print(root->left);
    print(root->right);
}

int main() {
    node* root = buildTree();
    print(root);
    cout << endl;
    return 0;
}