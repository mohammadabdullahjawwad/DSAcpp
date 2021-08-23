#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

#define vi vector<int>
#define pii pair<int ,int>
#define all(v) v.begin(), v.end()
#define pub push_back
#define pob pop_back
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

int main() {
    OJ;
    FIO;
    ll n, w, h;
    cin >> n;
    ll x[n], y[n];
    for(ll i=0; i<n; i++) {
        cin >> x[i] >> y[i];
    }
    // Sorting - To find the order of occurrences of towers
    sort(x, x+n);
    sort(y, y+n);
    h = y[n-1] - y[0];
    w = x[n-1] - x[0];
    // Calculate delta x and delta y
    ll dx = 0;
    ll dy = 0;
    for(int i=1; i<n; i++) {
        dx = max(dx, x[i]-x[i-1]-1);
        dy = max(dy, y[i]-y[i-1]-1);
    }
    cout << dx*dy << endl;
    return 0;
}