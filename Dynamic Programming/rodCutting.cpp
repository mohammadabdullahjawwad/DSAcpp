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
#define clr(dp) memset(dp,0,sizeof(dp))

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int profitTD(int* a, int n, int* dp) {
    // Base Case
    if(!n) {
        return 0;
    }
    // Look Up
    if(dp[n]) {
        return dp[n];
    }
    // Recursive Case
    int ans = INT_MIN;
    for(int i=1; i<=n; i++) {
        int gain = a[i] + profitTD(a, n-i, dp);
        ans = max(ans, gain);
    }
    return dp[n] = ans;
}

int profitBU(int*a, int n) {
    int dp[1000000] = {0};
    int ans = INT_MIN;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            ans = max(ans, a[j] + dp[i-j]);
        }
        dp[i] = ans;
    }
    return ans;
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    int *a = new int[n];
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    int dp[1000000] = {0}; // It stores the maximum profit for a given length
    cout << profitTD(a, n, dp) << endl;
    cout << profitBU(a, n) << endl;
    return 0;
}