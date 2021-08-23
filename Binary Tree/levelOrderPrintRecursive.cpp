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

node *buildRecursive() {
    int d;
    cin >> d;
    if(d == -1) {
        return NULL;
    }
    node* root = new node(d);
    root->left = buildRecursive();
    root->right = buildRecursive();
    return root;
}

int height(node* root) {
    if(root == NULL) {
        return 0;
    }
    int hl = height(root->left);
    int hr = height(root->right);
    return max(hl, hr) + 1;
}

void printKthLevel(node* root, int k) {
    if(root == NULL) {
        return;
    }
    if(k == 1) {
        cout << root->data << " ";
        return;
    }
    printKthLevel(root->left, k-1);
    printKthLevel(root->right, k-1);
    return;
}

void print(node *root) {
    for(int i=1; i<=height(root); i++) {
        printKthLevel(root, i);
        cout << endl;
    }
}

int main() {
    node* root = buildRecursive();
    print(root);
    return 0;
}