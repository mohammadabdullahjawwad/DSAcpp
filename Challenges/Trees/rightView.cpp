#include <iostream>
#include <vector>
#include <queue>
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

class Solution {
    vector<int> v;
    int max_level = -1;
    void helper(node *root, int level) {
        if(root == NULL) {
            return;
        }
        if(max_level < level) {
            max_level = level;
            v.push_back(root->data);
        }
        helper(root->right, level+1);
        helper(root->left, level+1);
    }
public:
    vector<int> rightView(node* root) {
        helper(root, 0);
        return v;
    }
};

node* build() {
    int data;
    cin >> data;
    if(data == -1) {
        return NULL;
    }
    queue<node* > q;
    node* root = NULL;
    root = new node(data);
    q.push(root);
    while(!q.empty()) {
        cin >> data;
        if(data != -1) {
            node* n = new node(data);
            q.front()->left = n;
            q.push(n);
        }
        cin >> data;
        if(data != -1) {
            node* n = new node(data);
            q.front()->right = n;
            q.push(n);
        }
        q.pop();
    }
    return root;
}

int main() {
    Solution s;
    node* root = build();
    vector<int> v = s.rightView(root);
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}