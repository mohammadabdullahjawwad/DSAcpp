#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define vi vector <int>
#define pii pair <int ,int>
#define all(v) v.begin(),v.end()
#define pub push_back
#define pob pop_back
#define mp make_pair
#define ll long long int
#define MOD 1000000007
#define clr(val) memset(val,0,sizeof(val))

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

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
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->left->right->right = new node(8);
    root->right->right->right = new node(9);

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