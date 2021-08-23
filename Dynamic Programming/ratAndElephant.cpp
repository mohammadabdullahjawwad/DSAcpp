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

int dp[100][100] = {0};

// O(n*n)
int rat(int r, int c) {
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            // Base Case
            if(!i || !j ) {
                dp[i][j] = 1;
            }
            // If cell (i, j) is blocked, dp[i][j] = 0
            else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    return dp[r-1][c-1];
}

int fact(int n) {
    int dp[n+1] = {0};
    dp[0] = dp[1] = 1;
    if(dp[n]) {
        return dp[n];
    }
    for(int i=2; i<=n; i++) {
        dp[i] = i * dp[i-1];
    }
    return dp[n];
}

// O(n) - This formla cannot be applied if some cells are blocked (Gives runtime error - integer overflow in leetcode)
int ratOptimized(int r, int c) {
    return fact(r-1 +c-1) / (fact(r-1) * fact(c-1));
}

// Multiple possible values (stops) for same path in case of element
int elephant(int r, int c) {
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            // Base Case
            if(!i && !j ) {
                dp[i][j] = 1;
            }
            else if(!i) {
                for(int k=0; k<i; k++) {
                    dp[i][j] += dp[k][j];
                }
            }
            else if(!j) {
                for(int k=0; k<j; k++) {
                    dp[i][j] += dp[i][k];
                }
            }
            else {
                for(int k=0; k<i; k++) {
                    dp[i][j] += dp[k][j];
                }
                for(int k=0; k<j; k++) {
                    dp[i][j] += dp[i][k];
                }
            }
        }
    }
    return dp[r-1][c-1];
}

int main() {
    OJ;
    FIO;
    int r, c;
    cin >> r >> c;
    cout << rat(r, c) << endl;
    cout << ratOptimized(r, c) << endl;
    cout << elephant(r, c) << endl;
    return 0;
}