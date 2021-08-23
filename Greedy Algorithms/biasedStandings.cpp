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
    // Algorithm similar to counting sort
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll val[n+1] = {0};
        for(int i=0; i<n; i++) {
            string name;
            ll rank;
            cin >> name >> rank;
            val[rank]++;
        }
        // Greedy algorithm - assign nearest rank to the one asked for
        ll badness = 0;
        ll givenRank = 1;
        for(int i=1; i<=n; i++) {
            while(val[i]) {
                badness += abs(givenRank - i);
                val[i]--;
                givenRank++;
            }
        }
        cout << badness << endl;
    }
    return 0;
}