// TLE : Do this problem using DP

#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int tiling(int n, int m) {
    if(n > 0 && n < m) {
        return 1;
    }
    if(n == m) {
        return 2;
    }
    return tiling(n - 1, m) + tiling(n - m, m);
}

int main() {
    OJ;
    FIO;
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        cout << tiling(n, m) << endl;
    }
    return 0;
}