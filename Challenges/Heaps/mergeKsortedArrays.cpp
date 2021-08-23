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
    int k, n;
    cin >> k >> n;
    vector<vector<int>> a;
    for(int i=0; i<k; i++) {
        vector<int> v;
        for(int j=0; j<n; j++) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        a.push_back(v);
    }
    vector<int> ans = mergeKSortedArrays(a);
    for(auto x: ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}