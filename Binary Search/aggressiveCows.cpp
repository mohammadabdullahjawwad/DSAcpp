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

bool isValidConfig(vll& a, ll n, ll dist, ll c) {
    ll cow = 1;
    ll pos = a[0];
    for(ll i=1; i<n; i++) {
        if(a[i] - pos >= dist) {
            pos = a[i];
            cow++;
            if(cow == c) {
                return true;
            }
        }
    }
    return false;
}

ll binarySearch(vll& a, ll& n, ll c) {
    ll s = a[0];
    ll e = a[n-1] - a[0];
    ll mx = 0;
    while(s <= e) {
        ll m = s + (e - s) / 2;
        if(isValidConfig(a, n, m, c)) {
            mx = m;
            s = m + 1;
        }
        else {
            e = m - 1;
        }
    }
    return mx;
}

void solve() {
    ll n, c;
    cin >> n >> c;
    vll a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    cout << binarySearch(a, n, c) << endl;
}

int main() {
    OJ;
    FIO;
    ll t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}