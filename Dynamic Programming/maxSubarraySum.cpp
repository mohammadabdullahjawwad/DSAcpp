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

// Dynamic Programming Approach
int maxSum(int* arr, int n) {
    int dp[1000000] = {0};
    dp[0] = arr[0]>0 ? arr[0] : 0;
    int ans = dp[0];
    for(int i=1; i<n; i++) {
        dp[i] = dp[i-1] + arr[i];
        if(dp[i] < 0) {
            dp[i] = 0;
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

// Space Optimisation - Kadane's Algorithm
int maxSpaceOpt(int* arr, int n) {
    int csum = 0;
    int ans = 0;
    for(int i=0; i<n; i++) {
        csum += arr[i];
        if(csum < 0) {
            csum = 0;
        }
        ans = max(ans, csum);
    }
    return ans;
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout << maxSum(arr, n) << endl;
    cout << maxSpaceOpt(arr, n) << endl;
    return 0;
}