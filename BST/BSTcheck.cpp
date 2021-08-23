#include <iostream>
#include <climits>
using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;
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

node* build() {
    int data;
    cin >> data;
    node *root = NULL;
    while(data != -1) {
        root = insert(root, data);
        cin >> data;
    }
    return root;
}

bool bstCheck(node* root, int minV = INT_MIN, int maxV = INT_MAX) {
    if(root == NULL) {
        return true;
    }
    if(root->data >= minV && root->data <= maxV && bstCheck(root->left, minV, root->data) && bstCheck(root->right, root->data, maxV)) {
        return true;
    }
    return false;
}

int main() {
    node* root = build();
    if(bstCheck(root)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}