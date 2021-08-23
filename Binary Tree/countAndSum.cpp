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

node* build() {
    int d;
    cin >> d;
    if(d == -1) {
        return NULL;
    }
    node* root = new node(d);
    root->left = build();
    root->right = build();
    return root;
}

int count(node* root) {
    if(root == NULL) {
        return 0;
    }
    return 1 + count(root->left) + count(root->right); // It becomes preorder traversal
}

int sum(node* root) {
    if(root == NULL) {
        return 0;
    }
    return root->data + sum(root->left) + sum(root->right); // It becomes preorder traversal
}

int main() {
    node *root = build();
    cout << count(root) << endl;
    cout << sum(root) << endl;
    return 0;
}