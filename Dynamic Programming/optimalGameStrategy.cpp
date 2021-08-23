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

ll a[100005];
ll dp[5000][5000];

ll optimalStrategy(ll s, ll e) {
    if(s > e) {
        return 0;
    }
    if(s<5000 && e<5000) {
        if(dp[s][e] != -1) {
            return dp[s][e];
        }
    }
    ll case1 = a[s] + min(optimalStrategy(s+2, e), optimalStrategy(s+1, e-1));
	ll case2 = a[e] + min(optimalStrategy(s, e-2), optimalStrategy(s+1, e-1));
    ll ans = max(case1, case2);
    if(s<5000 && e<5000) {
        dp[s][e] = ans;
    }
    return ans;
}

int main() {
    OJ;
    FIO;
    ll n;
    cin >> n;
    for(ll i=0; i<n; i++) {
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << optimalStrategy(0, n-1) << endl;
    return 0;
}