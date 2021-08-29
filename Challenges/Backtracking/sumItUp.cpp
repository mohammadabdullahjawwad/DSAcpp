#include <bits/stdc++.h>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

set<vector<int>> s;

void sumUp(vector<int>& a, vector<int> out, int ans, int i, int n, int key) {
    if(i == n) {
        if(ans == key) {
            sort(out.begin(), out.end());
            s.insert(out);
        }
        return;
    }
    out.push_back(a[i]);
    sumUp(a, out, ans + a[i], i + 1, n, key);
    out.pop_back();
    sumUp(a, out, ans, i + 1, n, key);
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    int key;
    cin >> key;
    vector<int> out;
    sumUp(a, out, 0, 0, n, key);
    for(auto v: s) {
        for( int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}