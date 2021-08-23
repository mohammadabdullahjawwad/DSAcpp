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
    int t;
    cin >> t;
    vector<pii> v;
    while (t--) {
        int n;
        cin >> n;
        int s, e;
        for(int i=0; i<n; i++) {
            cin >> s >> e;
            v.pub(mp(s, e));
        }
        // Activity selection algorithm
        // Sort all activities according to finishing time
        sort(all(v), compare);
        // Start picking activities
        int act = 1;
        int fin = v[0].second;
        // Iterate over the remaining activities
        for(int i=1; i<v.size(); i++) {
            if(v[i].first >= fin) {
                act++;
                fin = v[i].second;
            }
        }
        cout << act << endl;
        v.clear();
    }
    return 0;
}