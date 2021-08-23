#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

vector<pair<int, int>> twosum(vector<int> a, int key) {
    vector<pair<int, int>> ans;
    sort(a.begin(), a.end());
    int n = a.size();
    int l = 0, r = n - 1;
    while(l <= r) {
        if(a[l] + a[r] == key) {
            ans.push_back({a[l], a[r]});
            l++;
            r--;
        }
        else if(a[l] + a[r] < key) {
            l++;
        }
        else {
            r--;
        }
    }
    return ans;
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
    vector<pair<int, int>> ans = twosum(a, key);
    for(auto p:ans) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}