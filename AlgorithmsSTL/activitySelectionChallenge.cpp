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

bool compare(pair<int, int>& a, pair<int, int>& b) {
    return a.second < b.second;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> act(n);
    for (int i = 0; i < n; i++) {
        cin >> act[i].first >> act[i].second;
    }
    if(n == 0) {
        cout << 0 << endl;
        return;
    }
    sort(act.begin(), act.end(), compare);
    pair<int, int> curr(act[0]);
    int ans = 1;
    for (int i=1; i<n; i++) {
        if(act[i].first >= curr.first && act[i].second <= curr.second) {
            curr = act[i];
        }
        if(curr.second <= act[i].first) {
            curr = act[i];
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    OJ;
    FIO;
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}