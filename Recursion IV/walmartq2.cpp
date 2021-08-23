#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

bool factcomp(int a, int b) {
    return a > b;
}

bool markcomp(pair<int, int>& a, pair<int, int>& b) {
    return a.second > b.second;
}

int maximiseProfit(int qty, vector<pair<int, int>>& market) {
    int ans = 0;
    int i = 0;
    while(qty) {

        int q = qty >= market[i].first ?  market[i].first : qty;
        ans += q * market[i].second;
        qty -= q;
        i++;
    }
    return ans;
}

void print(vector<vector<int>>& dp, int n, int k) {
    for(int i = 0; i <=n; i++) {
        for(int j = 0; j <=k; j++) {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }
}

int profit(int n, int m, int k, vector<int>& factory, vector<pair<int, int>>& market, vector<int>& rent) {
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    // print(dp, n, k);
    for(int i=1; i<=n; i++) {
        dp[i][0] = maximiseProfit(factory[i-1], market);
    }
    // print(dp, n, k);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=k; j++) {
            if(j > i) {
                dp[i][j] = dp[i][j-1];
            }
            else {
                dp[i][j] = max(rent[j-1] + dp[i-j][0], dp[i][j-1]);
            }
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }
    // print(dp, n, k);
    return dp[n][k];
}

int main() {
    OJ;
    FIO;

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> factory(n);
    for(int i=0; i<n; i++) {
        cin >> factory[i];
    }
    sort(factory.begin(), factory.end(), factcomp);
    for(int i=1; i<n; i++) {
        factory[i] += factory[i-1];
    }

    vector<pair<int, int>> market(m);
    for(int i=0; i<m; i++) {
        cin >> market[i].first >> market[i].second;
    }
    sort(market.begin(), market.end(), markcomp);

    vector<int> rent(k);
    for(int i=0; i<k; i++) {
        cin >> rent[i];
    }
    sort(rent.begin(), rent.end(), factcomp);
    for(int i=1; i<k; i++) {
        rent[i] += rent[i-1];
    }

    cout << profit(n, m, k, factory, market, rent) << endl;
    
    return 0;
}
