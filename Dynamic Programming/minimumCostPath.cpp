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

int a[100][100];
int dp[100][100] = {0};

int minCost(int r, int c) {
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            // Base Case
            if(!i && !j) {
                dp[i][j] = a[0][0];
            }
            else if(!i) {
                dp[i][j] = dp[0][j-1] + a[0][j];
            }
            else if(!j) {
                dp[i][j] = dp[i-1][0] + a[i][0];
            }
            else {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + a[i][j];
            }
        }
    }
    return dp[r-1][c-1];
}

int main() {
    OJ;
    FIO;
    int r, c;
    cin >> r >> c;
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> a[i][j];
        }
    }
    cout << minCost(r, c) << endl;
    return 0;
}