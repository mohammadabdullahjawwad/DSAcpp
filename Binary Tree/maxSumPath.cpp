#include <iostream>
#include <climits>
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

node* build() {
    int data;
    cin >> data;
    if(data == -1) {
        return NULL;
    }
    node* root = new node(data);
    root->left = build();
    root->right = build();
    return root;
}

class Solution {
public:
    int ans = INT_MIN;

    int maxSum(node* root) {

        // Base Case
        if(root == NULL) {
            return 0;
        }

        // Recursive Case
        int left = maxSum(root->left);
        int right = maxSum(root->right);

        // Self Work
        int case1 = root->data;
        int case2 = left + root->data;
        int case3 = root->data + right;
        int case4 = left + root->data + right;
        ans = max(case1, max(case2, max(case3, max(case4, ans))));
        return max(left, max(right, 0)) + root->data;
        // This '0' is written because if left and right are less than 0, but the root->data is greater than 0, we can omit both left and right int the ans. We return the contribution of this node to its parent in order to check whether this parent child pair is to be considered for the ans as well or not
    }
};

int main() {
    node* root = build();
    Solution s;
    int max = s.maxSum(root);
    cout << s.ans << endl;
    return 0;
}