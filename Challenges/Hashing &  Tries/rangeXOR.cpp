#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>
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

class trieNode {
public:
    trieNode* left; // Represents 0
    trieNode* right; // Represents 1
    vi v;
};

void insert(int n, trieNode* head, int index) {
    trieNode* curr = head;
    for(int i=31; i>=0; i--) { // Assuming a number is going to have a maximum of 32 bits
        int bit = (n >> i) & 1; // Find ith bit
        if(!bit) {
            if(curr->left == NULL) {
                curr->left = new trieNode();
            }
            curr->v.pub(index);
            curr = curr->left;
        }
        else {
            if(curr->right == NULL) {
                curr->right = new trieNode();
            }
            curr->v.pub(index);
            curr = curr->right;
        }
    }
    curr->v.pub(index);
}

bool binarySearchRange(vi v, int left, int right) {
    int l = 0;
    int h = v.size() - 1;
    while(l <= h) {
        int m = (l+h)/2;
        int val = v[m];
        if(val >= left && val <= right) {
            return true;
        }
        else if(val < left) {
            l = m + 1;
        }
        else if(val > right) {
            h = m - 1;
        }
    }
    return false;
}

int maxXor(trieNode* head, int el, int l, int r) {
    trieNode* curr = head;
    int value = el;
    int cxor = 0;
    for(int i=31; i>=0; i--) {
        int bit = (value >> i) & 1;
        if(!bit) { // Current bit is 0
            if(curr->right != NULL && binarySearchRange(curr->right->v, l, r)) {
                curr = curr->right;
                cxor += (int)pow(2, i);
            }
            else {
                curr = curr->left;
            }
        }
        else { // Current bit is 1
            if(curr->left != NULL && binarySearchRange(curr->left->v, l, r)) {
                curr = curr->left;
            }
            else {
                cxor += (int)pow(2, i);
                curr = curr->right;
            }
        }
    }
    return cxor;
}

int main() {
    OJ;
    FIO;
    trieNode* head = new trieNode();
    int q;
    cin >> q;
    int index = 0;
    while(q--) {
        int t;
        cin >> t;
        if(!t) {
            int x;
            cin >> x;
            insert(x, head, index);
            index++;
        }
        else if(t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            cout << maxXor(head, x, l-1, r-1) << endl;
        }
    }
    return 0;
}

// 2/3 test cases failed