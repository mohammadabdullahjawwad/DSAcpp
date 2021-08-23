#include <bits/stdc++.h>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    int number;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> number;
        ans ^= number;
    }
    cout << ans << endl;
    return 0;
}