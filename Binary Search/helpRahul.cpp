#include <iostream>
#include <vector>
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

ll search(vll& a, ll s, ll e, ll& key) {
    // Base Case
    if(s > e) {
        return -1;
    }
    // Recursive Case
    ll m = s + (e - s) / 2;
    if(a[m] == key) {
        return m;
    }
    // Case 1 : Mid lies in the Left Part of the array implies left part is sorted
    if(a[s] <= a[m]) {
        // Case 1A : Element lies to the left of mid (sorted part)
        if(key>=a[s] && key<=a[m]) {
            return search(a, s, m-1, key);
        }
        // Case 1B : Element lies to the right of mid
        return search(a, m+1, e, key);
    }
    // Case 2 : Mid lies in the Right Part of the array implies right part is sorted
    // Case 2A : Element lies to the right of mid (sorted part)
    if(key>=a[m] && key<=a[e]) {
        return search(a, m+1, e, key);
    }
    // Case 2B : Element lies to the left of mid
    return search(a, s, m-1, key);
}

int main() {
    ll n;
    cin >> n;
    vll a(n);
    for(ll i=0; i<n; i++) {
        cin >> a[i];
    }
    ll key;
    cin >> key;
    cout << search(a, 0, n-1, key) << endl;
    return 0;
}