#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, pair<int, int>> custom;

vector<int> mergeKSortedArrays(vector<vector<int>> a) {
    vector<int> result;
    priority_queue<custom, vector<custom>, greater<custom>> p;
    for(int i=0; i<a.size(); i++) {
        p.push({a[i][0], {i, 0}});
    }
    while(!p.empty()) {
        custom current = p.top();
        p.pop();
        int x = current.second.first;
        int y = current.second.second;
        result.push_back(current.first);
        if(y + 1 < a[x].size()) {
            p.push({a[x][y+1], {x, y+1}});
        }
    }
    return result;
}

int main() {
    // int n1;
    // cin >> n1;
    // int a[n1];
    // for(int i=0; i<n1; i++) {
    //     cin >> a[i];
    // }
    // int n2;
    // cin >> n2;
    // int b[n2];
    // for(int i=0; i<n2; i++) {
    //     cin >> b[i];
    // }
    // int n3;
    // cin >> n3;
    // int c[n3];
    // for(int i=0; i<n3; i++) {
    //     cin >> c[i];
    // }
    // priority_queue<int, vector<int>, greater<int>> p;
    // for(int i=0; i<n1; i++) {
    //     p.push(a[i]);
    // }
    // for(int i=0; i<n2; i++) {
    //     p.push(b[i]);
    // }
    // for(int i=0; i<n3; i++) {
    //     p.push(c[i]);
    // }
    // vector<int> ans;
    // while(p.size()) {
    //     ans.push_back(p.top());
    //     p.pop();
    // }
    // for(int i=0; i<ans.size(); i++) {
    //     cout << ans[i] << " ";
    // }
    // cout << endl;
    vector<vector<int>> a{{2, 6, 12, 15}, {1, 9, 13, 15}, {20, 24, 30, 32}, {-1, 3, 4, 5}};
    vector<int> ans = mergeKSortedArrays(a);
    for(auto x: ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}