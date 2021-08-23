#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    int value;
    node* left;
    node* right;
    node(int data) {
        value = data;
        left = NULL;
        right = NULL;
    }
};

node* insert(node* root, int data) {
    if(root == NULL) {
        return new node(data);
    }
    if(data <= root->value) {
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
    while (data != -1) {
        root = insert(root, data);
        cin >> data;
    }
    return root;
}

node* largestMin(node* root) {
    while(root->right != NULL) {
        root = root->right;
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
    if(key < root->value) {
        root->left = deleteNode(root->left, key);
        return root;
    }
    if(key > root->value) {
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
    // node* replacement = largestMin(root->left);
    node* replacement = smallestMax(root->right);
    root->value = replacement->value;
    // root->left = deleteNode(root->left, replacement->value);
    root->right = deleteNode(root->right, replacement->value);
    return root;
}

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
            cout << front->value << " ";
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

int main() {
    node* root = build();
    int key;
    cin >> key;
    root = deleteNode(root, key);
    bfs(root);
    return 0;
}