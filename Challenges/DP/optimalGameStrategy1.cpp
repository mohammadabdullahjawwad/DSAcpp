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

int dp[1000][1000] = {0};

int optimalStrategy(int* a, int s, int e) {
    if(s > e) {
        return 0;
    }
    if(e == s+1) {
        return dp[s][e] = max(a[s], a[e]);
    }
    if(dp[s][e]) {
        return dp[s][e];
    }
    return dp[s][e] = max(a[s] + min(optimalStrategy(a, s+2, e), optimalStrategy(a, s+1, e-1)), a[e] + min(optimalStrategy(a, s, e-2), optimalStrategy(a, s+1, e-1)));
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    cout << optimalStrategy(a, 0, n-1) << endl;
    return 0;
}