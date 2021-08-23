#include <iostream>
#include <utility>
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

node* build() {
    int d;
    cin >> d;
    if (d == -1) {
        return NULL;
    }
    node* root = new node(d);
    root->left = build();
    root->right = build();
    return root;
}

pair<int, bool> heightBalanced(node* root) {
    pair<int, bool> p;
    if(root == NULL) {
        p.first = 0;
        p.second = true;
        return p;
    }
    pair<int, bool> left = heightBalanced(root->left);
    pair<int, bool> right = heightBalanced(root->right);
    p.first = max(left.first, right.first) + 1;
    if(abs(left.first-right.first) <= 1 && left.second && right.second) {
        p.second = true;
    }
    else {
        p.second = false;
    }
    return p;
}

int main() {
    node*root = build();
    if(heightBalanced(root).second) {
        cout << "Balanced" << endl;
    }
    else {
        cout << "Unbalanced" << endl;
    }
    return 0;
}