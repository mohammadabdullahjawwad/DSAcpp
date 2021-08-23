#include <iostream>
#include <queue>
#include <map>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int data) : data(data), left(NULL), right(NULL) {};
};

node* build() {
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

void topView(node* root, int hd, int level, map<int, pair<int, int>>& hashmap) { // We pass the map by reference so that we change the pair.first (i.e. node->data) value stored in the map whenever required
    if(!root) {
        return;
    }
    if(!hashmap.count(hd)) { // If no entry is present corresponding to the current hd
        hashmap[hd] = make_pair(root->data, level);
    }
    else if(hashmap[hd].second > level) { // For two nodes having the same hd, the one with lower level is to be stored since it becomes a part of the top view
        hashmap[hd] = make_pair(root->data, level);
    }
    topView(root->left, hd-1, level+1, hashmap);
    topView(root->right, hd+1, level+1, hashmap);
}

void printTopView(node* root) {
    map<int, pair<int, int>> hashmap; // This map stores the level and horizontal distance (hd) of all nodes. hd is stored as key and node->data, level are stored respectively (pair) as mapvalue
    topView(root, 0, 0, hashmap); // It fills all entries for the map created above
    for(auto it : hashmap) { // It prints all the node->data values present in map
        cout << it.second.first << " ";
    }
}

int main() {
    node* root = build();
    printTopView(root);
    cout << endl;
    return 0;
}