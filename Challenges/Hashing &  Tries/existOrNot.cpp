#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

#define vi vector<int>
#define pii pair<int ,int>
#define all(v) v.begin(), v.end()
#define mp make_pair
#define ll long long int
#define MOD 1000000007
#define clr(val) memset(val,0,sizeof(val))

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

bool search(unordered_set<ll> us, int n) {
    if(us.count(n)) {
        return true;
    }
    return false;
}

int main() {
    OJ;
    FIO;
    int t;
    cin >> t;
    while (t--) {
        int l;
        cin >> l;
        ll* a = new ll[l];
        unordered_set<ll> us;
        for(int i=0; i<l; i++) {
            cin >> a[i];
            us.insert(a[i]);
        }
        int q;
        cin >> q;
        while(q--) {
            ll n;
            cin >> n;
            if(us.find(n) != us.end()) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}

// Lesson learnt - find() is faster than count() for searching