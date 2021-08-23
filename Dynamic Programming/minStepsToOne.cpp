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

int minStepsTD(int n, int* dp) {
    // Base Case
    if(n == 1) {
        return 0;
    }
    // Look Up
    if(dp[n]) {
        return dp[n];
    }
    // Recursive Case
    int mod3,  mod2, minus1;
    mod3 = mod2= minus1 = INT_MAX;
    if(n % 3 == 0) {
        mod3 = minStepsTD(n/3, dp);
    }
    if(n % 2 == 0) {
        mod2 = minStepsTD(n/2, dp);
    }
    minus1 = minStepsTD(n-1, dp);
    int ans = min(mod3, min(mod2, minus1)) + 1;
    return dp[n] = ans;
}

int minStepsBU(int n) {
    if(n == 1) {
        return 0;
    }
    int dp[1000000] = {0};
    for(int i=2; i<=n; i++) {
        int mod3,  mod2, minus1;
        mod3 = mod2= minus1 = INT_MAX;
        if(n%3 == 0) {
            mod3 = dp[i/3];
        }
        if(n%2 == 0) {
            mod2 = dp[i/2];
        }
        minus1 = dp[i-1];
        dp[i] = min(mod3, min(mod2, minus1)) + 1;
    }
    return dp[n];
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    int dp[10000] = {0};
    cout << minStepsTD(n, dp) << endl;
    cout << minStepsBU(n) << endl;
    return 0;
}