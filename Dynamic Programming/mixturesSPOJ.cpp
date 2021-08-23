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

// #define FIO \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(NULL); \
//     cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int a[100000000];
ll dp[1000][1000];

ll sum(int s, int e) {
    ll ans = 0;
    for(int i=s; i<=e; i++) {
        ans += a[i];
        ans %= 100;
    }
    return ans;
}

ll mixtures(int s, int e) {
    // Base Case - Smoke generated for single element is 0. Also it is 0 if s > e
    if(s >= e) {
        return 0;
    }
    // Check Up
    if(dp[s][e] != -1) {
        return dp[s][e];
    }
    dp[s][e] = INT_MAX;
    // Break expression at every s <= k <= e
    for(int k=s; k<=e; k++) {
        dp[s][e] = min(dp[s][e], mixtures(s, k)+mixtures(k+1, e)+sum(s, k)*sum(k+1, e));
    }
    return dp[s][e];
}

int main() {
    OJ;
    // FIO;
    int n;
    while((scanf("%d", &n)) != EOF) { // No of test cases not known. Hence we read till the end of the file (EOF)
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=n; j++) {
                dp[i][j] = -1;
            }
        }
        cout << mixtures(0, n-1) << endl;
    }
    return 0;
}