#include <iostream>
#include <queue>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

node* buildUsingArray(int a[], int s, int e) {
    if(s > e) {
        return NULL;
    }
    int mid = (s + e)/2;
    node* root = new node(a[mid]);
    root->left = buildUsingArray(a, s, mid-1);
    root->right = buildUsingArray(a, mid+1, e);
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
    int a[1000001];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    node* root = buildUsingArray(a, 0, n-1);
    bfs(root);
    return 0;
}