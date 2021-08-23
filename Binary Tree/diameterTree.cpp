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

int height(node* root) {
    if(root == NULL) {
        return 0;
    }
    int hl = height(root->left);
    int hr = height(root->right);
    return max(hl, hr) + 1;
}

// Approach 1 - O(N^2)
int diameter(node * root) {
    if(root == NULL) {
        return 0;
    }
    // Preorder traversal
    int hl = height(root->left);
    int hr = height(root->right);
    int a1 = hl + hr; // Root - O(N) not O(1)
    int a2 = diameter(root->left); // Left
    int a3 = diameter(root->right); // Right
    return max(a1, max(a2, a3));
}

// Approach 2 (Optimized) starts here
pair<int, int> diameterFast(node *root) {
    pair<int, int> p;
    if(root == NULL) {
        p.first = 0; // first => height
        p.second = 0; // second => diameter
        return p;
    }

    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);

    p.first = max(left.first, right.first) + 1;
    p.second = max(left.first+right.first, max(left.second, right.second));
    return p;
}
// Approach 2 ends here

int main() {
    node* root = build();
    cout << diameter(root) << endl;
    cout << diameterFast(root).second << endl; // We just have to print the diameter
    return 0;
}