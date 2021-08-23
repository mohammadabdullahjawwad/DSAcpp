#include<iostream>
#include<cmath>
using namespace std;

#define ll long long int

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

ll kthRoot(ll n, int k) {
    ll s = 0;
    ll e = n;
    ll ans;
    while(s <= e) {
        ll m = s + (e - s) / 2;
        if(pow(m, k) == n) {
            return m;
        }
        else if(pow(m, k) < n) {
            ans = m;
            s = m + 1;
        }
        else {
            e = m - 1;
        }
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
        int k;
        cin >> n >> k;
        cout << kthRoot(n, k) << endl;
    }
	return 0;
}