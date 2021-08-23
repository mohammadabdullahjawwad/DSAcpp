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

int minCoinsTD(int n, int* coins, int den, int *dp) {
    // Base Case
    if(!n) {
        return 0;
    }
    // Lookup
    if(dp[n]) {
        return dp[n];
    }
    // Recursive Case
    int ans = INT_MAX;
    for(int i=0; i<den; i++) {
        if(n - coins[i] >= 0) {
            int subprob = minCoinsTD(n-coins[i], coins, den, dp);
            ans = min(ans, subprob+1);
        }
    }
    dp[n] = ans;
    return dp[n];
}

int minCoinsBU(int n, int *coins, int den) {
    if(!n) {
        return 0;
    }
    int dp[1000000] = {0};
    for(int i=1; i<=n; i++) {
        dp[i] = INT_MAX;
        for(int c=0; c<den; c++) {
            if(i - coins[c] >= 0) {
                int subprob = dp[i - coins[c]];
                dp[i] = min(dp[i], subprob+1);
            }
        }
    }
    return dp[n];
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    int den;
    cin >> den;
    int *coins = new int[den];
    for(int i=0; i<den; i++) {
        cin >> coins[i];
    }
    int dp[100000] = {0};
    cout << minCoinsTD(n, coins, den, dp) << endl;
    cout << minCoinsBU(n, coins, den) << endl;
    return 0;
}