#include <iostream>
#include <stack>
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

void zigzag(node* root) {
    if(root == NULL) {
        return;
    }
    stack<node *> current, next;
    current.push(root);
    bool lTOr = true;
    while(!current.empty()) {
        node* temp = current.top();
        current.pop();
        if(temp) {
            cout << temp->data << " ";
            if(lTOr) {
                if(temp->left) {
                    next.push(temp->left);
                }
                if(temp->right) {
                    next.push(temp->right);
                }
            }
            else {
                if(temp->right) {
                    next.push(temp->right);
                }
                if(temp->left) {
                    next.push(temp->left);
                }
            }
            if(current.empty()) {
                lTOr = !lTOr;
                swap(current, next);
            }
        }
    }
    cout << endl;
}

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

int main() {
    node* root = create("true");
    zigzag(root);
    return 0;
}