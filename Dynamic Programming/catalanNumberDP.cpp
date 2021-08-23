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
    freopen("output.txt", "w", stdout)

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

int bst(int n) {
    int dp[n+1] = {0};
    dp[0] = dp[1] = 1;
    if(dp[n]) {
        return dp[n];
    }
    for(int i=2; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            dp[i] += dp[j-1] * dp[i-j];
        }
    }
    return dp[n];
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    cout << bst(n) << endl;
    int bt = fact(n) * bst(n);
    cout << bt << endl;
    return 0;
}