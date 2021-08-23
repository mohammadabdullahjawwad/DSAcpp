#include <iostream>
#include<bitset>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

bitset<30> col, d1, d2;

void solve(int r, int n, int &ans) {
    if(r == n) {
        ans++;
        return;
    }
    for(int c=0; c<n; c++) {
        // Check whether it is a safe position or not
        if(!col[c] && !d1[r - c + n - 1] && !d2[r + c]) { // the isValid() function runs in O(1) time
            col[c] = d1[r - c + n - 1] = d2[r + c] = 1;
            solve(r + 1, n, ans);
            // Backtracking
            col[c] = d1[r - c + n - 1] = d2[r + c] = 0;
        }
    }
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    int ans = 0;
    solve(0, n, ans);
    cout << ans << endl;
    return 0;
}