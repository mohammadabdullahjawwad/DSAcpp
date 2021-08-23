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
    cout << (present == true ? "Present" : "Absent") << endl;
    auto lb = lower_bound(a.begin(), a.end(), key); // Return the first element >= key
    cout << "Lower bound : " << lb - a.begin() << endl;
    auto ub = upper_bound(a.begin(), a.end(), key); // Return the first element > key
    cout <<"Upper bound : " << ub - a.begin() << endl;
    cout << "Frequency : " << ub - lb << endl;
    // Both upper_bound() and lower_bound() function in log(n) time
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