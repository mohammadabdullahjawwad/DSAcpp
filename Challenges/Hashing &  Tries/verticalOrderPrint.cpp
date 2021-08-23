#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <map>
using namespace std;

#define vi vector<int>
#define pii pair<int ,int>
#define all(v) v.begin(), v.end()
#define pub push_back
#define mp make_pair
#define ll long long int
#define MOD 1000000007
#define clr(val) memset(val,0,sizeof(val))

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO \
       ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

class node {
public:
    int data;
    node* left;
    node* right;
    node(int data) : data(data), left(NULL), right(NULL) {};
};

node* levelOrderBuild() {
    int data;
    cin >> data;
    if(data == -1) {
        return NULL;
    }
    queue<node* > q;
    node* root = NULL;
    root = new node(data);
    q.push(root);
    while(!q.empty()) {
        cin >> data;
        if(data != -1) {
            node* n = new node(data);
            q.front()->left = n;
            q.push(n);
        }
        cin >> data;
        if(data != -1) {
            node* n = new node(data);
            q.front()->right = n;
            q.push(n);
        }
        q.pop();
    }
    return root;
}

void verticalOrder(node* root, int hd, map<int, vector<int>> &m) { // pass the map by reference
    // Base Case
    if(root == NULL) return;
    // Recursive Case
    m[hd].pub(root->data);
    verticalOrder(root->left, hd-1, m);
    verticalOrder(root->right, hd+1, m);
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    node* root = levelOrderBuild();
    map<int, vector<int>> m;
    int hd = 0;
    verticalOrder(root, hd, m); // Fills the map
    for(auto p : m) {
        // cout << p.first << " : "; // We don't need to print the key
        for(auto i : p.second) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}