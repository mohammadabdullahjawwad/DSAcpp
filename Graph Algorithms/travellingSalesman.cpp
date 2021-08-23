#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <climits>
#include <map>
#include <list>
#include <queue>
#include <math.h>
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

vector<vi> dist; // Adjacency matrix
int dp[1000][100];

int travellingSalesman(int mask, int pos, int visitedAll) { // mask tells us which cities have been visited. pos tells us which city to start from
    if(mask == visitedAll) { // Base Case
        return dist[pos][0];
    }
    // Lookup
    if(dp[mask][pos] != -1) {
        return dp[mask][pos];
    }
    int ans = INT_MAX;
    // Try to visit an unvisited city
    for(int city=0; city<dist.size(); city++) {
        if((mask & (1<<city)) == 0) { // City not visited
            int newAns = dist[pos][city] + travellingSalesman(mask|(1<<city), city, visitedAll);
            ans = min(ans, newAns);
        }
    }
    return dp[mask][pos] = ans;
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    // Initially, all value in dp array = -1
    for(int i=0; i<(1<<n); i++) {
        for(int j=0; j<n; j++) {
            dp[i][j] = -1;
        }
    }
    for(int i=0; i<n; i++) {
        vi row;
        for(int j=0; j<n; j++) {
            int x;
            cin >> x;
            row.pub(x);
        }
        dist.pub(row);
    }
    int visitedAll = (1 << n) - 1;
    cout << travellingSalesman(1, 0, visitedAll) << endl;
    return 0;
}