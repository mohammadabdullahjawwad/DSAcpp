#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <cmath>
#include <map>
#include <list>
#include <stack>
#include <queue>
using namespace std;

#define vll vector<ll>
#define pll pair<ll, ll>
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

float squareRoot(ll n, ll p) {
    ll s = 0;
    ll e = n;
    float ans = -1;
    // Integral Part - Binary Search
    while (s <= e) {
        ll m = s + (e - s) / 2; // We can equivalently write m = (s + e) >> 1
        if(m * m == n) {
            return m;
        }
        if(m * m < n) {
            ans = m;
            s = m + 1;
        }
        else {
            e = m-1;
        }
    }
    // Fractional Part - Brute Force
    float inc = 0.1;
    for(ll i=0; i<p; i++) {
        while (ans*ans <= n) {
            ans += inc;
        }
        ans -= inc; // ans has overshot the required value, we need to come one step back
        inc /= 10;
    }
    return ans;
}

void solve() {
    ll n, p;
    cin >> n >> p;
    cout << squareRoot(n, p) << endl;
}

int main() {
    OJ;
    FIO;
    // ll t;
    // cin >> t;
    // while(t--) {
        solve();
    // }
    return 0;
}