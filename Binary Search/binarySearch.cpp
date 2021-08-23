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

ll binarySearch(vll& a, ll& n, ll& key) {
    ll s = 0;
    ll e = n - 1;
    while(s <= e) {
        int m = s + (e - s) / 2;
        if(key == a[m]) {
            return m;
        }
        if(key > a[m]) {
            s = m + 1;
        }
        else {
            e = m - 1;
        }
    }
    return -1;
}

void solve() {
    ll n;
    cin >> n;
    vll a(n);
    for(ll i=0; i<n; i++) {
        cin >> a[i];
    }
    ll key;
    cin >> key;
    ll index = binarySearch(a, n, key);
    if(index == -1) {
        cout << key << " is not present" << endl;
    }
    else {
        cout << key << " is present at index " << index << endl;
    }
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