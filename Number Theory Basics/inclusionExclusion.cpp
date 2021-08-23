// This question also goes by the name not so easy math and avengers endgame
#include <iostream>
#include <vector>
using namespace std;

#define ll long long int

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int main() {
    OJ;
    FIO;
    ll t;
    cin >> t;
    vector<ll> primes{2, 3, 5, 7, 11, 13, 17, 19};
    while(t--) {
        ll n;
        cin >> n;
        ll subsets = (1 << 8) - 1; // We skip the empty set. Since we have 8 primes, there will be 2^8 subsets
        ll ans = 0;
        for(ll i=1; i<=subsets; i++) {
            ll den = 1ll; // Defining 1 in type ll. This is necessary for shift operators to be used
            ll setBits = __builtin_popcount(i);
            for(int j=0; j<8; j++) {
                if(i & (1 << j)) {
                    den = den * primes[j];
                }
            }
            if(setBits & 1) {
                ans += n / den;
            }
            else {
                ans -= n / den;
            }
        }
        cout << ans << endl;
    }
    return 0;
}