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

node* create(string isPresent) {
    if(isPresent != "true") {
        return NULL;
    }
    int data;
    cin >> data;
    node* root = new node(data);
    string left;
    cin >> left;
    root->left = create(left);
    string right;
    cin >> right;
    root->right = create(right);
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
    node* root = create("true");
    if(heightBalanced(root).second) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}