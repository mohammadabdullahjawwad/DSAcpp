#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) : data(data), left(NULL), right(NULL){};
};

TreeNode* create(string isPresent) {
    if(isPresent != "true") {
        return NULL;
    }
    int data;
    cin >> data;
    TreeNode* root = new TreeNode(data);
    string left;
    cin >> left;
    root->left = create(left);
    string right;
    cin >> right;
    root->right = create(right);
    return root;
}

bool identical(TreeNode* tree1, TreeNode* tree2) {
    if(tree1 == NULL && tree2 == NULL) {
        return true;
    }
    if((tree1 && tree2) && identical(tree1->left, tree2->left) && identical(tree1->right, tree2->right)) {
        return true;
    }
    return false;
}

int main() {
    TreeNode* tree1 = create("true");
    TreeNode* tree2 = create("true");
    if(identical(tree1, tree2)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}

// This is not complete. 2/4 test cases being passed