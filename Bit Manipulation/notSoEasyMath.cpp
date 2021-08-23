#include<iostream>
using namespace std;

#define ll long long int

int main() {
    ll t;
    cin >> t;
    ll primes[] = {2, 3, 5, 7, 11, 13, 17, 19};
    while(t--) {
        ll n;
        cin >> n;
        ll subsets = (1<<8) - 1;
        ll ans = 0;
        for(ll i=1; i<=subsets; i++) {
            ll den = 1;
            ll set = __builtin_popcount(i);
            for(ll j=0; j<8; j++) {
                if(i&(1<<j)) {
                    den *= primes[j];
                }
            }
            if(set & 1) {
                ans += n/den;
            } else {
                ans -= n/den;
            }
        }
        cout << ans << endl;
    }
    return 0;
}