#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>

#define ll long long int

using namespace std;

vector<ll> subsets(vector<ll> v) {
    vector<ll> ans;
    ans.clear();
    ll n = v.size(); // n <= 17 <= 10^6
    // Bitmasking - To find subset {(1<<n) = (2^n)-1}
    for(ll i=0; i<(1<<n); i++) {
        ll j = 0;
        ll sum = 0;
        for(ll no=i; no>0; no=no>>1) {
            if(no & 1) {
                sum += v[j];
            }
            j++;
        }
        ans.push_back(sum);
    }
    return ans;
}

int main() {
    vector<ll> v1,v2; // At most 17 elements in each vector
    ll n, a, b;
    cin >> n >> a >> b;
    ll n1 = n/2;
    ll n2 = n - n1;
    for(ll i=0; i<n1; i++) {
        ll x;
        cin >> x;
        v1.push_back(x);
    }
    for(ll i=0; i<n2; i++) {
        ll x;
        cin >> x;
        v1.push_back(x);
    }
    vector<ll> sv1, sv2;
    sv1 = subsets(v1);
    sv2 = subsets(v2);
    // Sort sv2 for binary search
    sort(sv2.begin(), sv2.end());
    // Matching using binary search
    ll ans = 0;
    for(ll i=0; i<sv1.size(); i++) {
        ll lo = a - sv1[i];
        ll hi = b - sv1[i];
        ll m1 = lower_bound(sv2.begin(), sv2.end(), lo) - sv2.begin();
        ll m2 = upper_bound(sv2.begin(), sv2.end(), hi) - sv2.begin();
        ans += (m2-m1);
    }
    cout << ans << endl;
    return 0;
}