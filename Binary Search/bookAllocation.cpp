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

bool isValidConfig(vll& book, ll n, ll m, ll ans) {
    ll student = 1;
    ll pages = 0;
    for(ll i=0; i<n; i++) {
        if(pages + book[i] > ans) {
            pages = book[i];
            student++;
            if(student > m) {
                return false;
            }
        }
        else {
            pages += book[i];
        }
    }
    return true;
}

ll page(vll& book, ll n, ll m) {
    if(n < m) {
        return -1;
    }
    ll e = 0;
    ll s = 0;
    for(ll i=0; i<n; i++) {
        e += book[i];
        s = max(s, book[i]);
    }
    // Search space : book with most pages (s) to sum of pages of all books (e)
    ll ans = s;
    while(s <= e) {
        ll mid = s + (e - s) / 2;
        if(isValidConfig(book, n, m, mid)) {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return ans;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vll book(n);
    for(ll i=0; i<n; i++) {
        cin >> book[i];
    }
    cout << page(book, n, m) << endl;
}

int main() {
    OJ;
    FIO;
    ll t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}