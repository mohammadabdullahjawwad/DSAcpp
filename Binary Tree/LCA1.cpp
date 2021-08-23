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

bool ancestors(node* root, int p, vector<int> &vp) {
    if(root == NULL) {
        return false;
    }
    if(root->data == p || ancestors(root->left, p, vp) || ancestors(root->right, p, vp)) {
        vp.push_back(root->data);
        return true;
    }
    return false;
}

int main() {
    node* root = create();
    int p, q;
    cin >> p >> q;
    vector<int> vp, vq, result;
    if(ancestors(root, p, vp) && ancestors(root, q, vq)) {
        int lp = vp.size();
        int lq = vq.size();
        int i = min(lp, lq);
        for(; i>=0; i--) {
            if(vp[lp] == vq[lq]) {
                result.push_back(vp[lp]);
            }
            lp--;
            lq--;
        }
    }
    if(result.size()) {
        cout << result[result.size()-1] << endl;
    }
    return 0;
}