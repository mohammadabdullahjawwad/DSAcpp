#include <iostream>
#include <queue>
#include <algorithm>
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

node* create(int* pre, int* in, int s, int e) {
    static int i = 0;
    if(s > e) {
        return NULL;
    }
    if(s == e) {
        return new node(pre[i++]);
    }
    // Recursive Case
    node* root = new node(pre[i]);
    int index = -1;
    for(int j=s; j<=e; j++) {
        if(pre[i] == in[j]) {
            index = j;
            break;
        }
    }
    i++;
    if(index >= 1) {
        root->left = create(pre, in, s, index-1);
    }
    root->right = create(pre, in, index+1, e);
    return root;
}

void bfs(node *root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        node* front = q.front();
        if(front == NULL) {
            cout << endl;
            q.pop();
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout << front->data << " ";
            q.pop();
            if(front->left) {
                q.push(front->left);
            }
            if(front->right) {
                q.push(front->right);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    int pre[n], in[n];
    for(int i=0; i<n; i++) {
        cin >> pre[i];
        in[i] = pre[i];
    }
    sort(in, in + n);
    node *root = create(pre, in, 0, n-1);
    bfs(root);
    return 0;
}

// Problem incomplete