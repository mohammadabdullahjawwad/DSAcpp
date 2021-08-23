#include <iostream>
using namespace std;

int tiling(int n, int m) {
    if(n > 0 && n < m) {
        return 1;
    } else if(n == m) {
        return 2;
    }
    return tiling(n-1, m) + tiling(n-m, m);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        cout << tiling(n, m) << endl;
    }
    return 0;
}

// TLE : Do this problem after doing DP
// As of now the problem is not complete