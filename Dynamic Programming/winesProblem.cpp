#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
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

int winesTD(int* p, int i, int j, int y, int dp[][1000]) {
    // Base Case
    if(i > j) {
        return 0;
    }
    // Value Check - If particular case has already been computed
    if(dp[i][j]) {
        return dp[i][j];
    }
    // Recursive Case
    int opt1 = p[i]*y + winesTD(p, i+1, j, y+1, dp);
    int opt2 = p[j]*y + winesTD(p, i, j-1, y+1, dp);
    return dp[i][j] = max(opt1, opt2);
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    int* p = new int[n];
    for(int i=0; i<n; i++) {
        cin >> p[i];
    }
    int dp[1000][1000] = {0};
    cout << winesTD(p, 0, n-1, 1, dp) << endl;
    return 0;
}