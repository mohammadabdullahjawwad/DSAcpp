#include <iostream>
#include <climits>
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

class info {
public:
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

info largest(node* root) {
    if(root == NULL) {
        return {0, INT_MIN, INT_MAX, 0, true};
    }
    if(root->left == NULL && root->right == NULL) {
        return {1, root->data, root->data, 1, true};
    }
    info l = largest(root->left);
    info r = largest(root->right);
    info result;
    result.size = (1 + l.size + r.size);
    if(l.isBST && r.isBST && l.max <= root->data && r.min > root->data) {
        result.min = min(l.min, root->data);
        result.max = max(r.max, root->data);
        result.ans = result.size;
        result.isBST = true;
        return result;
    }
    result.ans = max(l.ans, r.ans);
    result.isBST = false;
    return result;
}

// ================================
// Simple but inefficient approach
// ================================
// class Solution {
//     bool isBST(node* root, int min, int max) {
//         if(root == NULL) {
//             return true;
//         }
//         if(root->data < min || root->data > max) {
//             return false;
//         }
//         return isBST(root->left, min, root->data) && isBST(root->right, root->data, max);
//     }
//     int size(node* root) {
//         if(root == NULL) {
//             return 0;
//         }
//         return 1 + size(root->left) + size(root->right);
//     }
// public:
//     int largest(node* root) {
//         if(isBST(root, INT_MIN, INT_MAX)) {
//             return size(root);
//         }
//         return max(largest(root->left), largest(root->right));
//     }
// };

int main() {
    int n;
    cin >> n;
    int pre[n];
    for(int i=0; i<n; i++) {
        cin >> pre[i];
    }
    int in[n];
    for(int i=0; i<n; i++) {
        cin >> in[i];
    }
    node* root = build(pre, in, 0, n-1);
    // Solution s;
    // cout << s.largest(root) << endl;
    cout << largest(root).ans << endl;
    return 0;
}