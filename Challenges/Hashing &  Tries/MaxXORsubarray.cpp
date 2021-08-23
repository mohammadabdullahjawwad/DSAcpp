#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
using namespace std;

#define vi vector<int>
#define pii pair<int ,int>
#define all(v) v.begin(), v.end()
#define mp make_pair
#define ll long long int
#define MOD 1000000007
#define clr(val) memset(val,0,sizeof(val))

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class trieNode {
public:
    trieNode* left; // Represents 0
    trieNode* right; // Represents 1
};

void insert(int n, trieNode* head) {
    trieNode* curr = head;
    for(int i=31; i>=0; i--) { // Assuming a number is going to have a maximum of 32 bits
        int bit = (n >> i) & 1; // Find ith bit
        if(!bit) {
            if(curr->left == NULL) {
                curr->left = new trieNode();
            }
            curr = curr->left;
        }
        else {
            if(curr->right == NULL) {
                curr->right = new trieNode();
            }
            curr = curr->right;
        }
    }
}

int maxXor(trieNode* head, int el) {
    trieNode* curr = head;
    int value = el;
    int cxor = 0;
    for(int i=31; i>=0; i--) {
        int bit = (value >> i) & 1;
        if(!bit) { // Current bit is 0
            if(curr->right != NULL) {
                curr = curr->right;
                cxor += (int)pow(2, i);
            }
            else {
                curr = curr->left;
            }
        }
        else { // Current bit is 1
            if(curr->left != NULL) {
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
    int n;
    cin >> n;
    int* a = new int[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    trieNode* head = new trieNode();
    int result = INT_MIN;
    int pre = 0;
    insert(pre, head);
    for(int i=0; i<n; i++) {
        pre = pre ^ a[i];
        insert(pre, head);
        int x = maxXor(head, pre);
        x = x ^ pre;
        result = max(result, x);
    }
    cout << result << endl;
    return 0;
}