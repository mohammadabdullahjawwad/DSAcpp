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

int partyTD(int n, int* dp) {
    if(dp[n]) {
        return dp[n];
    }
    if(n < 3) {
        return dp[n] = n;
    }
    return dp[n] = partyTD(n-1, dp) + (n - 1) * partyTD(n-2, dp);
}

int partyBU(int n) {
    int dp[n+1];
    for(int i=0; i<=n; i++) {
        if(i <= 2) {
            dp[i] = i;
        }
        else {
            dp[i] = dp[i-1] + (i-1) * dp[i-2];
        }
    }
    return dp[n];
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    int dp[n+1] = {0};
    cout << partyTD(n, dp) << endl;
    cout << partyBU(n) << endl;
    return 0;
}