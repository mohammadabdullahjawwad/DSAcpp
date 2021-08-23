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

bool compare(pii p1, pii p2) {
    return p1.second < p2.second;
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    vector<pii> v;
    for(int i=0; i<n; i++) {
        int c, r;
        cin >> c >> r;
        v.pub(mp(c-r, c+r));
    }
    sort(all(v), compare);
    int ans = 0;
    int s = v[0].second;
    for(int i=1; i<v.size(); i++) {
        if(v[i].first <= s) {
            ans++;
        }
        else {
            s = v[i].second;
        }
    }
    cout << ans << endl;
    return 0;
}