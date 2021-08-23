#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
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
    return p1.first > p2.first;
}

int main() {
    OJ;
    FIO;
    int t;
    cin >> t;
    while(t--) {
        vector<pii> v; // stores d (distance from town) and f
        priority_queue<int> pq; // stores f
        int n;
        cin >> n;
        for(int i=0; i<n; i++) {
            int d, f;
            cin >> d >> f;
            v.pub(mp(d, f));
        }
        // Sort fuel stations according to d and f
        sort(all(v), compare);
        int l, p;
        cin >> l >> p;
        int flag = 0;
        int ans = 0;
        // Update distance of fuel stations from truck
        for(int i=0; i<n; i++) {
            v[i].first = l - v[i].first;
        }
        int prev = 0; // no of previously visited stations
        int x = 0; // current station no
        while(x < n) {
            // If there is enough fuel to go to next station
            if(p >= v[x].first-prev) { // We equated distance with fuel as fuel leak is equal to distance covered
                p -= v[x].first-prev;
                pq.push(v[x].second);
                prev = v[x].first;
            }
            else {
                // Check if some fuel stations visited in the priority_queue
                if(pq.empty()) {
                    flag = 1;
                    break;
                }
                // Refuel with fuel station of highest capacity in priority_queue
                p += pq.top();
                // Remove the fuel station from the priority_queue
                pq.pop();
                ans += 1;
                continue; // In order to ensure condition on line 60
            }
            x++;
        }
        // Travelled through n fuel stations
        // Reach town from final fuel station
        if(flag == 1) { // If there isn't enough fuel to reach next station
            cout << -1 << endl;
            continue;
        }
        l -= v[n-1].first;
        // If there is enough fuel to reach the town
        if(p >= l) {
            cout << ans << endl;
            continue;
        }
        // If there is enough fuel in priority_queue to reach the town
        while(p < l) {
            if(pq.empty()) {
                flag = 1;
                break;
            }
            p += pq.top();
            pq.pop();
            ans += 1;
        }
        if(flag == 1) {
            cout << -1 << endl;
            continue;
        }
        cout << ans << endl;
    }
    return 0;
}