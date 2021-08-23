#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <climits>
using namespace std;

#define vi vector<int>
#define pii pair<int ,int>
#define all(v) v.begin(), v.end()
#define pub push_back
#define pob pop_back
#define mp make_pair
#define ll long long int
#define MOD 1000000007
#define clr(val) memset(val,0,sizeof(val))

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int dp[1001][1001];

int paths(int r, int c) {
    // Base Case
    if(dp[0][0]== -1) {
        return 0;
    }
    // First Row
    for(int j=0; j<c; j++) {
        if(dp[0][j] == -1) {
            break;
        }
        dp[0][j] = 1;
    }
    // First Column
    for(int i=0; i<r; i++) {
        if(dp[i][0] == -1) {
            break;
        }
        dp[i][0] = 1;
    }
    // Bottom Up DP for rest of the matrix
    for(int i=1; i<r; i++) {
        for(int j=1; j<c; j++) {
            // If the cell is blocked
            if(dp[i][j] == -1) {
                continue;
            }
            dp[i][j] = 0;
            if(dp[i][j-1] != -1) {
                dp[i][j] = dp[i][j-1] % MOD;
            }
            if(dp[i-1][j] != -1) {
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % MOD;
            }
        }
    }
    // If final cell is blocked
    if(dp[r-1][c-1] == -1) {
        return 0;
    }
    return dp[r-1][c-1];
}

int main() {
    OJ;
    FIO;
    memset(dp, 0, sizeof(dp));
    int m, n, p;
    cin >> m >> n >> p;
    for(int i=0; i<p; i++) {
        int x, y;
        cin >> x >> y;
        dp[x-1][y-1] = -1;
    }
    cout << paths(m, n) << endl;
    return 0;
}