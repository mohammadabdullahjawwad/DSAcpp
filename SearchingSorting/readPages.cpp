#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long int

bool isValidConfig(ll *book, ll n, ll m, ll ans) {
    int student = 1;
    ll pages = 0;
    for(int i=0; i<n; i++) {
        if(pages+book[i] > ans) {
            pages = book[i];
            student++;
            if(student > m) {
                return false;
            }
        } else {
            pages += book[i];
        }
    }
    return true;
}
ll page(ll *book, ll n, ll m) {
    ll sum = 0;
    ll s=0, e=0;
    for(int i=0; i<n; i++) {
        sum += book[i];
        s = max(s, book[i]);
    }
    e = sum;
    ll ans = s;
    while(s <= e) {
        ll mid = (s+e)/2;
        if(isValidConfig(book, n, m, mid)) {
            ans = mid;
            e = mid-1;
        } else {
            s = mid+1;
        }
    }
    return ans;
}
int main() {
    ll n, m;
    cin >> n >> m;
    ll book[n];
    for(int i=0; i<n; i++) {
        cin >> book[i];
    }
    cout << page(book, n, m) << endl;
}