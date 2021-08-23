#include <iostream>
#include <climits>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int profit(int* weights, int* prices, int n, int c) {
    if(n == 0 ||c == 0) {
        return 0;
    }
    int ans = 0;
    int inc = INT_MIN;
    if(weights[n - 1] <= c) {
        inc = prices[n - 1] + profit(weights, prices, n - 1, c - weights[n - 1]);
    }
    int exc = profit(weights, prices, n - 1, c);
    ans = max(inc, exc);
    return ans;
}

int main() {
    OJ;
    FIO;
    int n, c;
    cin >> n >> c;
    int* weights = new int[n];
    int* prices = new int[n];
    for(int i=0; i<n; i++) {
        cin >> weights[i];
    }
    for(int i=0; i<n; i++) {
        cin >> prices[i];
    }
    cout << profit(weights, prices, n, c) << endl;
    return 0;
}