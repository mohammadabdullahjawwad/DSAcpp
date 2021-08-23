#include <bits/stdc++.h>
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

// Simple DP - O(n*n)
int lis1(int*a, int n) {
    int dp[n] = {1}; // Every element in itself is a LIS of length 1 (worst case)
    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

// Tricky - O(n*n)
int lis2(int*a, int n) {
    int dp[n+1]; // Since we need all lengths from 0 to n
    dp[0] = INT_MIN;
    for(int i=1; i<=n; i++) {
        dp[i] = INT_MAX;
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(dp[j] < a[i] && a[i] < dp[j+1]) {
                dp[j+1] = a[i];
            }
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++) {
        if(dp[i] != INT_MAX) {
            ans = i;
        }
    }
    return ans;
}

// Tricky + Binary Search - O(n logn)
int lis3(int* a, int n) {
    int dp[n+1]; // Since we need all lengths from 0 to n
    dp[0] = INT_MIN;
    for(int i=1; i<=n; i++) {
        dp[i] = INT_MAX;
    }
    for(int i=0; i<n; i++) {
        int len = upper_bound(dp, dp+n+1, a[i]) - dp;
        if(dp[len-1] < a[i] && a[i] < dp[len]) {
            dp[len] = a[i];
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++) {
        if(dp[i] != INT_MAX) {
            ans = i;
        }
    }
    return ans;
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    int* a = new int[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    cout << lis1(a, n) << endl;
    cout << lis2(a, n) << endl;
    cout << lis3(a, n) << endl;
    return 0;
}