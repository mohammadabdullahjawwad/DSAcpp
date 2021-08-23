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

node* buildBST(int* a, int s, int e) {
    if(s > e) {
        return NULL;
    }
    int mid = (s + e) / 2;
    node* root = new node(a[mid]);
    root->left = buildBST(a, s, mid-1);
    root->right = buildBST(a, mid+1, e);
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

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        node* root = buildBST(a, 0, n-1);
        preorderPrint(root);
        cout << endl;
    }
    return 0;
}