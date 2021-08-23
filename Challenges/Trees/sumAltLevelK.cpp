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

node* buildtree() {
    int data, children;
    cin >> data >> children;
    node* root = new node(data);
    if(children > 0) {
        root->left = buildtree();
        if(children > 1) {
            root->right = buildtree();
        }
    }
    return root;
}

int ans = 0;

void sum(node* root, int level) {
    if(root == NULL) {
        return;
    }
    if(level == 0) {
        ans += root->data;
        return;
    }
    sum(root->left, level-1);
    sum(root->right, level-1);
}

int main() {
    node* root = buildtree();
    int level;
    cin >> level;
    sum(root, level);
    cout << ans << endl;
    return 0;
}