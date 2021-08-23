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

int lcs(char X[], char Y[]) {
    int m = strlen(X);
    int n = strlen(Y);
    int dp[100][100];
    // Base Cases - First Row and Column = 0
    for(int i=0; i<=m; i++) {
        dp[i][0] = 0;
    }
    for(int j=0; j<=n; j++) {
        dp[0][j] = 0;
    }
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            int ans = 0;
            if(X[i-1] == Y[j-1]) { // Since we consider "" at 0th index
                ans = 1 + dp[i-1][j-1];
            }
            else {
                ans = max(dp[i-1][j], dp[i][j-1]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[m][n];
}

int main() {
    OJ;
    FIO;
    char str1[100], str2[100];
    cin >> str1 >> str2;
    cout << lcs(str1, str2) << endl;
    return 0;
}