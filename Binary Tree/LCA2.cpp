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

node* create() {
    int data;
    cin >> data;
    if(data == -1) {
        return NULL;
    }
    node* root = new node(data);
    root->left = create();
    root->right = create();
    return root;
}

class custom {
public:
    bool pPresent;
    bool qPresent;
    node* ans;
    custom() {
        pPresent = false;
        qPresent = false;
        ans = NULL;
    }
};

custom* helper(node* root, int p, int q) {
    
    // Base Case
    if(root == NULL) {
        return NULL;
    }

    custom* leftAns = helper(root->left, p, q);

    // LCA in LST
    if(leftAns != NULL && leftAns->ans != NULL) {
        return leftAns;
    }

    custom* rightAns = helper(root->right, p, q);

    // LCA in RST
    if(rightAns != NULL && rightAns->ans != NULL) {
        return rightAns;
    }
    
    custom* result = new custom();

    // If the present node i.e. root is the answer
    if(leftAns != NULL && rightAns != NULL) {
        result->pPresent = true;
        result->qPresent = true;
        result->ans = root;
        return result;
    }

    // If q is present in a subtree of p
    else if(root->data == p) {
        result->pPresent = true;
        result->qPresent = (leftAns?leftAns->qPresent:false) || (rightAns?rightAns->qPresent:false);
        if(result->qPresent) {
            result->ans = root;
        }
        return result;
    }

    // If p is present in a subtree of q
    else if(root->data == q) {
        result->qPresent = true;
        result->pPresent = (leftAns?leftAns->pPresent:false) || (rightAns?rightAns->pPresent:false);
        if(result->pPresent) {
            result->ans = root;
        }
        return result;
    }

    // If only one of them is present
    else if(leftAns) {
        return leftAns;
    }
    else if(rightAns) {
        return rightAns;
    }

    // If both are not present
    return NULL;
}

int lca(node* root, int p, int q) {
    custom* result = helper(root, p, q);
    if(result == NULL) {
        return 0;
    }
    else {
        return result->ans->data;
    }
}

int main() {
    node* root = create();
    int p, q;
    cin >> p >> q;
    if(lca(root, p, q)) {
        cout << lca(root, p, q) << endl;
    }
    return 0;
}