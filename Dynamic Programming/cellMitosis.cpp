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

ll cellMitosis(int n, int x, int y, int z) {
    // Bottom Up Approach
    ll dp[n+1] = {0};
    for(int i=2; i<=n; i++) {
        if(n % 2) {
            dp[i] = min(dp[i-1]+y, dp[(i+1)/2]+x+z);
        }
        else {
            dp[i] = min(dp[i/2]+x, dp[i-1]+y);
        }
    }
    return dp[n];
}

int main() {
    OJ;
    FIO;
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    cout << cellMitosis(n, x, y, z) << endl;
    return 0;
}