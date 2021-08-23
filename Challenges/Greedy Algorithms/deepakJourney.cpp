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

int minFuel(ll* c, ll* l, ll n) {
    ll minimum = c[0];
    ll ans = c[0] * l[0];
    for(ll i = 1; i < n; i++) {
        minimum = min(minimum, c[i]);
        ans += minimum * l[i];
    }
    return ans;
}

int main() {
    OJ;
    FIO;
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll c[n];
        for(ll i = 0; i < n; i++) {
            cin >> c[i];
        }
        ll l[n];
        for(ll i = 0; i < n; i++) {
            cin >> l[i];
        }
        cout << minFuel(c, l, n) << endl;
    }
    return 0;
}