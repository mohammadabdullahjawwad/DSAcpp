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

void preorderPrint(node* root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

void keysInRange(node* root, int k1, int k2) {
    if(root == NULL) {
        return;
    }
    if(k1 < root->data) {
        keysInRange(root->left, k1, k2);
    }
    if(k1 <= root->data && root->data <= k2) {
        cout << root->data << " ";
    }
    if(k2 > root->data) {
        keysInRange(root->right, k1, k2);
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        node* root = NULL;
        while(n--) {
            int data;
            cin >> data;
            root = insert(root, data);
        }
        int k1, k2;
        cin >> k1 >> k2;
        cout << "# Preorder : ";
        preorderPrint(root);
        cout << endl;
        cout << "# Nodes within range are : ";
        keysInRange(root, k1, k2);
        cout << endl;
    }
    return 0;
}