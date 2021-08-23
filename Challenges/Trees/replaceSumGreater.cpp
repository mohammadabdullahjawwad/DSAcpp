#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int data) : data(data), left(NULL), right(NULL) {};
};

node* build(int* a, int s, int e) {
    if(s > e) {
        return NULL;
    }
    int mid = (s+e)/2;
    node* root = new node(a[mid]);
    root->left = build(a, s, mid-1);
    root->right = build(a, mid+1, e);
    return root;
}
int sum = 0;

node* replace(node* root) {
    if(root == NULL) {
        return NULL;
    }
    root->right = replace(root->right);
    sum += root->data;
    root->data = sum;
    root->left = replace(root->left);
    return root;
}

void prePrint(node* root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << " ";
    prePrint(root->left);
    prePrint(root->right);
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    node* root = build(a, 0, n-1);
    root = replace(root);
    prePrint(root);
    cout << endl;
    return 0;
}