#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
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

int ladderTD(int n, int k, int* dp) {
    // Base Case
    if(!n) {
        return 1;
    }
    // Look Up
    if(dp[n]) {
        return dp[n];
    }
    // Recursive Case
    int ways = 0;
    for(int i=1; i<=k; i++) {
        if(n-i >= 0) {
            ways += ladderTD(n-i, k, dp);
        }
    }
    return dp[n] = ways;
}

int ladderBU(int n, int k) {
    int dp[1000000] = {0};
    dp[0] = 1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=k; j++) {
            if(i-j >= 0) {
                dp[i] += dp[i-j];
            }
        }
    }
    return dp[n];
}

// Optimised Approach [O(N)]
int ladderOptimised(int n, int k) {
    int dp[1000000] = {0};
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=n; i++) {
        if(i > k) {
            dp[i] = 2*dp[i-1] - dp[i-k-1];
        }
        else {
            dp[i] = 2 * dp[i-1];
        }
    }
    return dp[n];
}

int main() {
    OJ;
    FIO;
    int n, k;
    cin >> n >> k;
    int dp[1000000] = {0};
    cout << ladderTD(n, k, dp) << endl;
    cout << ladderBU(n, k) << endl;
    cout << ladderOptimised(n, k) << endl;
    return 0;
}