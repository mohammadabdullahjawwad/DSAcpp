#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int optimalGame(int a[], int l, int r) {
    int case1 = 0, case2 = 0;
    if(l > r) {
        return 0;
    }
    case1 = a[l] + min(optimalGame(a, l + 2, r), optimalGame(a, l + 1, r - 1));
    case2 = a[r] + min(optimalGame(a, l, r - 2), optimalGame(a, l + 1, r - 1));
    return max(case1, case2);
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << optimalGame(a, 0, n - 1) << endl;
    return 0;
}