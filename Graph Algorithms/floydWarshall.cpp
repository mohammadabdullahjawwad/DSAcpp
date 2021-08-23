#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <climits>
#include <map>
#include <list>
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

void shortestPath(int n, vector<vi> &adj) {
    for(int k=1; k<=n; k++) {
        // Kth phase
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                adj[i][j] = min(adj[i][j], (adj[i][k]%MOD + adj[k][j]%MOD)%MOD);
            }
        }
    }
}

int main() {
    OJ;
    FIO;
    int v, e;
    cin >> v >> e;
    vector<vi> adj(v+1, vi(v+1, INT_MAX)); // n+1 X n+1
    for(int i=1; i<=v; i++) {
        adj[i][i] = 0;
    }
    while(e--) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x][y] = w;
        adj[y][x] = w;
    }
    shortestPath(v, adj);
    for(int i=1; i<=v; i++) {
        for(int j=1; j<=v; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}