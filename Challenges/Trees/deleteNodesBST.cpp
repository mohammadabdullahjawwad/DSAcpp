#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int data) : data(data), left(NULL), right(NULL) {};
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

node* build(int *a1, int n) {
    node* root = NULL;
    for(int i=0; i<n; i++) {
        root = insert(root, a1[i]);
    }
    return root;
}

node* smallestMax(node* root) {
    while(root->left != NULL) {
        root = root->left;
    }
    return root;
}

node* deleteNode(node* root, int key) {
    if(root == NULL) {
        return NULL;
    }
    if(key < root->data) {
        root->left = deleteNode(root->left, key);
        return root;
    }
    if(key > root->data) {
        root->right = deleteNode(root->right, key);
        return root;
    }
    // Case 1 : 0 children
    if(root->left == NULL && root->right == NULL) {
        delete root;
        return NULL;
    }
    // Case 2 : 1 child
    if(!(root->left && root->right)) {
        node* temp = (root->left)? root->left : root->right;
        delete root;
        return temp;
    }
    // Case 3 : 2 children
    node* replacement = smallestMax(root->right);
    root->data = replacement->data;
    root->right = deleteNode(root->right, replacement->data);
    return root;
}

void print(node* root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << " ";
    print(root->left);
    print(root->right);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a1[n];
        for(int i=0; i<n; i++) {
            cin >> a1[i];
        }
        node* root = build(a1, n);
        int m;
        cin >> m;
        int a2[m];
        for(int i=0; i<m; i++) {
            cin >> a2[i];
        }
        for(int i=0; i<m; i++) {
            root = deleteNode(root, a2[i]);
        }
        print(root);
        cout << endl;
    }
    return 0;
}