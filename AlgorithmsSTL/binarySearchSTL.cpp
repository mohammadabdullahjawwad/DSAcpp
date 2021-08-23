#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define vll vector<ll>
#define ll long long int

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void solve() {
    ll n;
    cin >> n;
    vll a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll key;
    cin >> key;
    bool present = binary_search(a.begin(), a.end(), key);
    cout << (present ? "Present" : "Absent") << endl;
    if(present) {
        auto lb = lower_bound(a.begin(), a.end(), key); // Returns the address of first element >= key. We can use int* instead of auto
        cout << "Lower bound : " << lb - a.begin() << endl;
        auto ub = upper_bound(a.begin(), a.end(), key); // Returns the address of first element > key
        cout <<"Upper bound : " << ub - a.begin() << endl;
        cout << "Frequency : " << ub - lb << endl;
        // Both upper_bound() and lower_bound() functions work in log(n) time
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