#include <iostream>
using namespace std;

#define ll long long int

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

ll power(ll a, ll b, ll c) {
    ll ans = 1;
    while(b > 0) {
        ll lbit = (b & 1);
        if(lbit) {
            ans = ((ans % c) * (a % c)) % c;
        }
        a = ((a % c) * (a % c)) % c;
        b >>= 1;
    }
    return ans % c;
}

int main() {
    OJ;
    FIO;
    ll a, b, c;
    cin >> a >> b >> c;
    cout << power(a, b, c) << endl;
    return 0;
}