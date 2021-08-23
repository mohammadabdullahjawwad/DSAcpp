// #include <iostream>
// using namespace std;

// class node {
// public:
//     int data;
//     node* left;
//     node* right;
//     node(int d) {
//         data = d;
//         left = NULL;
//         right = NULL;
//     }
// };

// node* build() {
//     int data;
//     cin >> data;
//     if(data == -1) {
//         return NULL;
//     }
//     node* root = new node(data);
//     root->left = build();
//     root->right = build();
//     return root;
// }

// class custom {
// public:
//     bool pPresent;
//     bool qPresent;
//     node* ans;
//     custom() {
//         pPresent = false;
//         qPresent = false;
//         ans = NULL;
//     }
// };

// custom* helper(node* root, int p, int q) {
    
//     // Base Case
//     if(root == NULL) {
//         return NULL;
//     }

//     custom* leftAns = helper(root->left, p, q);

//     // LCA in LST
//     if(leftAns != NULL && leftAns->ans != NULL) {
//         return leftAns;
//     }

//     custom* rightAns = helper(root->right, p, q);

//     // LCA in RST
//     if(rightAns != NULL && rightAns->ans != NULL) {
//         return rightAns;
//     }
    
//     custom* result = new custom();

//     // If the present node i.e. root is the answer
//     if(leftAns != NULL && rightAns != NULL) {
//         result->pPresent = true;
//         result->qPresent = true;
//         result->ans = root;
//         return result;
//     }

//     // If q is present in a subtree of p
//     else if(root->data == p) {
//         result->pPresent = true;
//         result->qPresent = (leftAns?leftAns->qPresent:false) || (rightAns?rightAns->qPresent:false);
//         if(result->qPresent) {
//             result->ans = root;
//         }
//         return result;
//     }

//     // If p is present in a subtree of q
//     else if(root->data == q) {
//         result->qPresent = true;
//         result->pPresent = (leftAns?leftAns->pPresent:false) || (rightAns?rightAns->pPresent:false);
//         if(result->pPresent) {
//             result->ans = root;
//         }
//         return result;
//     }

//     // If only one of them is present
//     else if(leftAns) {
//         return leftAns;
//     }
//     else if(rightAns) {
//         return rightAns;
//     }

//     // If both are not present
//     return NULL;
// }

// node* lca(node* root, int p, int q) {
//     custom* result = helper(root, p, q);
//     if(result == NULL) {
//         return NULL;
//     }
//     else {
//         return result->ans;
//     }
// }

// int distance(node* root, int p, int count) {
//     if(root == NULL) {
//         return -1;
//     }
//     if(root->data == p) {
//         return count;
//     }
//     int d = distance(root->left, p, count+1);
//     if(d != -1) {
//         return d;
//     }
//     d = distance(root->right, p, count+1);
//     return d;
// }

// int ans(node* root, int p, int q) {
//     if(root == NULL) {
//         return -1;
//     }
//     node* LCA = lca(root, p, q);
//     if(LCA == NULL) {
//         return -1;
//     }
//     return distance(LCA, p, 0) + distance(LCA, q, 0);
// }

// int main() {
//     node* root = build();
//     int p, q;
//     cin >> p >> q;
//     cout << ans(root, p, q) << endl;
//     return 0;
// }


// Alternate solution : ans = distance(lca, p) + distance(lca, q)

#include <iostream>
#include <climits>
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

class custom {
public:
    bool pPresent;
    bool qPresent;
    node* ans;
    custom() {
        pPresent = false;
        qPresent = false;
        ans = NULL;
    }
};

custom* helper(node* root, int p, int q) {
    
    // Base Case
    if(root == NULL) {
        return NULL;
    }

    custom* leftAns = helper(root->left, p, q);

    // LCA in LST
    if(leftAns != NULL && leftAns->ans != NULL) {
        return leftAns;
    }

    custom* rightAns = helper(root->right, p, q);

    // LCA in RST
    if(rightAns != NULL && rightAns->ans != NULL) {
        return rightAns;
    }
    
    custom* result = new custom();

    // If the present node i.e. root is the answer
    if(leftAns != NULL && rightAns != NULL) {
        result->pPresent = true;
        result->qPresent = true;
        result->ans = root;
        return result;
    }

    // If q is present in a subtree of p
    else if(root->data == p) {
        result->pPresent = true;
        result->qPresent = (leftAns?leftAns->qPresent:false) || (rightAns?rightAns->qPresent:false);
        if(result->qPresent) {
            result->ans = root;
        }
        return result;
    }

    // If p is present in a subtree of q
    else if(root->data == q) {
        result->qPresent = true;
        result->pPresent = (leftAns?leftAns->pPresent:false) || (rightAns?rightAns->pPresent:false);
        if(result->pPresent) {
            result->ans = root;
        }
        return result;
    }

    // If only one of them is present
    else if(leftAns) {
        return leftAns;
    }
    else if(rightAns) {
        return rightAns;
    }

    // If both are not present
    return NULL;
}

int lca(node* root, int p, int q) {
    custom* result = helper(root, p, q);
    if(result == NULL) {
        return 0;
    }
    else {
        return result->ans->data;
    }
}

int distance(node* root, int p) {
    int count = 0;
    if(root == NULL) {
        return INT_MIN;
    }
    if(root->data == p) {
        return count++;
    }
    count++;
    return max(distance(root->left, p), distance(root->right, p)) + 1;
}

int main() {
    node* root = build();
    int p, q;
    cin >> p >> q;
    int ans = distance(root, p) + distance(root, q) - 2*distance(root, lca(root, p, q));
    cout << ans << endl;
    return 0;
}