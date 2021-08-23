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

// Top Down Approach
int fibonacci(int n, int* dp) {
    // Base Case : n=0 or n=1
    if(n == 0 || n == 1) {
        return n;
    }
    // Look up if value is already computed
    if(dp[n]) {
        return dp[n];
    }
    // Recursive Case
    int ans;
    ans = fibonacci(n-1, dp) + fibonacci(n-2, dp);
    return dp[n] = ans;
}

// Bottom Up Approach
int fib(int n) {
    int dp[1000000] = {0};
    dp[1] = 1;
    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

// Space Optimisation for Bottom Up Approach
int fibOpt(int n) {
    if(n == 0 || n == 1) {
        return n;
    }
    int a = 0;
    int b = 1;
    int c;
    for(int i=2; i<=n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    cout << fib(n) << endl;
    cout << fibOpt(n) << endl;
    int dp[1000000] = {0};
    cout << fibonacci(n, dp) << endl;
    return 0;
}