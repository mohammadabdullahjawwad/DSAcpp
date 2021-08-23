#include <iostream>
#include <vector>
#include <string.h>
#include <climits>
using namespace std;

#define vi vector<int>
#define pii pair<int ,int>
#define all(v) v.begin(), v.end()
#define pub push_back
#define pob pop_back
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
    node* left;
    node* right;
    node() {
        left = NULL;
        right = NULL;
    }
};

class Trie {
    node* root;
public:
    Trie() {
        root = new node();
    }
    void insert(int n) {
        node* temp = root;
        for(int i=31; i>=0; i--) { // Assuming a number is going to have a maximum of 32 bits
            int bit = (n >> i) & 1; // Find ith bit
            if(!bit) {
                if(temp->left == NULL) {
                    temp->left = new node();
                }
                temp = temp->left;
            }
            else {
                if(temp->right == NULL) {
                    temp->right = new node();
                }
                temp = temp->right;
            }
        }
    }
    int maxXor(int value) {
    node* temp = root;
    int cxor = 0;
    for(int i=31; i>=0; i--) {
        int bit = (value >> i) & 1;
        if(!bit) { // current bit is 0
            if(temp->right != NULL) {
                temp = temp->right;
                cxor += (1 << i);
            }
            else {
                temp = temp->left;
            }
        }
        else { // current bit is 1
            if(temp->left != NULL) {
                temp = temp->left;
                cxor += (1 << i);
            }
            else {
                temp = temp->right;
            }
        }
    }
    return cxor;
}
};

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    int* a = new int [n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    int result = 0;
    int lbest[100000];
    int rbest[100000];
    int left = 0;
    int right = 0;
    Trie l;
    l.insert(0);
    for(int i=0; i<n; i++) {
        left ^= a[i];
        lbest[i] = max((!i)?0:lbest[i-1], l.maxXor(left));
        l.insert(left);
    }
    Trie r;
    r.insert(0);
    for(int i=n-1; i>=0; i--) {
        right ^= a[i];
        rbest[i] = max((i==n-1)?0:rbest[i+1], r.maxXor(right));
        r.insert(right);
        int value = rbest[i] + ((i==0)?INT_MIN:lbest[i-1]);
        result = max(result, value);
    }
    cout << result << endl;
    return 0;
}