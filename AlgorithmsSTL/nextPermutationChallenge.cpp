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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    next_permutation(a.begin(), a.end());
    for(int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
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