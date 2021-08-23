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
    int t;
    cin >> t;
    while(t--) {
        ll n, w, h;
        cin >> w >> h >> n;
        // Corner case - If there is no tower
        if(!n){
            cout<< w*h <<endl;
            continue;
        }
        ll x[n], y[n];
        for(ll i=0; i<n; i++) {
            cin >> x[i] >> y[i];
        }
        // Sorting - To find the order of occurrences of towers
        sort(x, x+n);
        sort(y, y+n);
        // Calculate delta x and delta y
        ll dx = x[0] - 1;
        ll dy = y[0] - 1;
        for(int i=1; i<n; i++) {
            dx = max(dx, x[i]-x[i-1]-1);
            dy = max(dy, y[i]-y[i-1]-1);
        }
        // Corner case - Space after last tower
        dx = max(dx, w-x[n-1]);
        dy = max(dy, h-y[n-1]);
        cout << dx*dy << endl;
    }
    return 0;
}