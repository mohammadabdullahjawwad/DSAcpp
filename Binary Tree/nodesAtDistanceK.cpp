#include <iostream>
#include <vector>
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

vector<int> result;

void moveDown(node* root, int k) {
    // Base Case
    if(root == NULL || k < 0) {
        return;
    }
    // Recursive Case
    if(k == 0 && root != NULL) {
        result.push_back(root->data);
        return;
    }
    moveDown(root->left, k-1);
    moveDown(root->right, k-1);
}

int answer(node* root, int k, int target) {
    if(root == NULL) {
        return -1;
    }
    if(root->data ==  target) {
        moveDown(root, k);
        return 1;
    }
    int L = answer(root->left, k, target);
    int R = answer(root->right, k, target);
    if(L != -1) {
        if(L == k) {
            result.push_back(root->data);
        }
        else {
            moveDown(root->right, k-L-1);
        }
        return L+1;
    }
    if(R != -1) {
        if(R == k) {
            result.push_back(root->data);
        }
        else {
            moveDown(root->left, k-R-1);
        }
        return R+1;
    }
    return -1;
}

int main() {
    node* root = create();
    int k, target;
    cin >> k >> target;
    if(answer(root, k, target)) {
        for(int i=0; i<result.size(); i++) {
            cout << result[i] << " ";
        }
    }
    cout << endl;
    return 0;
}