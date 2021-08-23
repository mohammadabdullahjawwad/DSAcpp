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

int mcm(vi a) {
    int dp[100][100];
    clr(dp);
    int n = a.size() - 1; // No of matrices = n - 1
    for(int i=1; i<n; i++) {
        int r = 0, c = i;
        while(c < n) {
            int ans = INT_MAX;
            for(int pivot=r; pivot<c; pivot++) {
                ans = min(ans, dp[r][pivot] + dp[pivot+1][c] + a[r]*a[pivot+1]*a[c+1]);
            }
            dp[r][c] = ans;
            r++, c++;
        }
    }
    return dp[0][n-1];
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    vi a;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        a.pub(x);
    }
    cout << mcm(a) << endl;
    return 0;
}