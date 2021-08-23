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

bool isValid(ll n, ll m, ll x, ll y, ll mid) {
    if(m + (n - mid) * y >= mid * x) {
        return true;
    }
    return false;
}

ll binarySearch(ll n, ll m, ll x, ll y) {
    ll s = 0;
    ll e = n;
    ll students = 0;
    while(s <= e) {
        ll mid = s + (e - s) / 2;
        if(isValid(n, m, x, y, mid)) {
            students = max(students, mid);
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return students;
}

void solve() {
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    cout << binarySearch(n, m, x, y) << endl;
}

int main() {
    OJ;
    FIO;
    solve();
    return 0;
}