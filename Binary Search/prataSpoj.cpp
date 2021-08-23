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

bool possible(vll& a, ll&n, ll& p, ll val) {
    ll time = 0;
    ll paratha = 0;
    for(ll i=0; i<n; i++) {
        time = a[i];
        ll multiplier = 2;
        while(time <= val) {
            paratha++;
            time += a[i] * multiplier;
            multiplier++;
        }
    }
    return paratha >= p;
}

ll binarySearch(vll& a, ll& n, ll& p) {
    ll s = 0;
    ll e = 1e8;
    ll ans = 0;
    while(s <= e) {
        ll mid = s + (e - s) / 2;
        if(possible(a, n, p, mid)) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return ans;
}

void solve() {
    ll p, l;
    cin >> p >> l;
    vll rank(l);
    for(ll i = 0; i<l; i++) {
        cin >> rank[i];
    }
    cout << binarySearch(rank, l, p) << endl;
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