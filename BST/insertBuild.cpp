#include <iostream>
#include <queue>
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

node* build() {
    int data;
    cin >> data;
    node* root = NULL;
    while(data != -1) { // It is ordered and hence only one -1. This marks the end of input
        root = insert(root, data);
        cin >> data;
    }
    return root;
}

// BFS Print
void bfs(node *root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        node* front = q.front();
        if(front == NULL) {
            cout << endl;
            q.pop();
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout << front->data << " ";
            q.pop();
            if(front->left) {
                q.push(front->left);
            }
            if(front->right) {
                q.push(front->right);
            }
        }
    }
}

// Inorder Print
void inorder(node * root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    node* root = build();
    inorder(root);
    cout << endl;
    bfs(root);
    return 0;
}