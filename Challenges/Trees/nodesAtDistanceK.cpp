#include <iostream>
#include <vector>
#include <bits/stdc++.h>
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

void moveDown(node* root, int k, vector<int>& result) {
    // Base Case
    if(root == NULL || k < 0) {
        return;
    }
    // Recursive Case
    if(k == 0 && root != NULL) {
        result.push_back(root->data);
        return;
    }
    moveDown(root->left, k-1, result);
    moveDown(root->right, k-1, result);
}

int answer(node* root, int k, int target, vector<int>& result) {
    if(root == NULL) {
        return -1;
    }
    if(root->data ==  target) {
        moveDown(root, k, result);
        return 1;
    }
    int L = answer(root->left, k, target, result);
    int R = answer(root->right, k, target, result);
    if(L != -1) {
        if(L == k) {
            result.push_back(root->data);
        }
        else {
            moveDown(root->right, k-L-1, result);
        }
        return L+1;
    }
    if(R != -1) {
        if(R == k) {
            result.push_back(root->data);
        }
        else {
            moveDown(root->left, k-R-1, result);
        }
        return R+1;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    int pre[n], in[n];
    for(int i=0; i<n; i++) {
        cin >> pre[i];
    }
    for(int i=0; i<n; i++) {
        cin >> in[i];
    }
    node* root = build(pre, in, 0, n-1);
    int t;
    cin >> t;
    while(t--) {
        int key, k;
        cin >> key >> k;
        vector<int> result;
        int ans = answer(root, k, key, result);
        if(result.size()) {
            sort(result.begin(), result.end());
            for(int i=0; i<result.size(); i++) {
                cout << result[i] << " ";
            }
        }
        else {
            cout << 0;
        }
        cout << endl;
    }
    return 0;
}