#include<iostream>
using namespace std;

#define ll long long int

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

bool valid(ll a[], ll n, ll k, ll target) {
    ll len = 0;
    ll painters = 1;
    for(ll i=0; i<n; i++) {
        len += a[i];
        if(len > target) {
            len = a[i];
            painters++;
            if(painters > k) {
                return false;
            }
        }
    }
    return true;
}

ll painter(ll a[], ll n, ll k, ll s, ll e) {
    ll ans = 0;
    while(s <= e) {
        ll mid = s + (e - s) / 2;
        if(valid(a, n, k, mid)) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return ans;
}

int main() {
    OJ;
    FIO;
    ll n, k, t;
    cin >> n >> k >> t;
    ll a[n];
    ll mx = 0;
    ll sum = 0;
    for(ll i=0; i<n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        sum += a[i];
    }
    ll ans = painter(a, n, k, mx, sum) * t;
    cout << ans % 10000003 << endl;
	return 0;
}