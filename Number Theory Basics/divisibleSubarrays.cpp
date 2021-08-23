#include <iostream>
#include <cstring>
using namespace std;

#define ll long long int

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

ll a[100000], cs[100000];

int main() {
    OJ;
    FIO;
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
		memset(cs, 0, sizeof(cs));
        cs[0] = 1; // Null subarray will always be there
        ll sum = 0;
        for(int i=0; i<n; i++) {
            cin >> a[i];
            sum += a[i];
            sum %= n;
            sum = (sum + n) % n;
            cs[sum]++;
        }
        ll ans = 0;
        for (int i=0; i<n; i++) {
            ans += cs[i] * (cs[i] - 1) / 2;
        }
        cout << ans << endl;
    }
    return 0;
}