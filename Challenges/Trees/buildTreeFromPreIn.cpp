#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int data) : data(data), left(NULL), right(NULL) {};
};

node* build(int *pre, int* in, int s, int e) {
    static int i = 0;
    if(s > e) {
        return NULL;
    }
    node *root = new node(pre[i]);
    int index = -1;
    for(int j=s; j<=e; j++) {
        if(in[j] == pre[i]) {
            index = j;
            break;
        }
    }
    i++;
    root->left = build(pre, in, s, index-1);
    root->right = build(pre, in, index+1, e);
    return root;
}

void print(node* root) {
    if(root == NULL) {
        return;
    }
    if(root->left == NULL) {
        cout << "END";
    }
    else {
        cout << root->left->data;
    }
    cout << " => " << root->data << " <= ";
    if(root->right == NULL) {
        cout << "END";
    }
    else {
        cout << root->right->data;
    }
    cout << endl;
    print(root->left);
    print(root->right);
}

int main() {
    int n;
    cin >> n;
    int pre[n];
    for(int i=0; i<n; i++) {
        cin >> pre[i];
    }
    cin >> n;
    int in[n];
    for(int i=0; i<n; i++) {
        cin >> in[i];
    }
    node* root = build(pre, in, 0, n-1);
    print(root);
    return 0;
}