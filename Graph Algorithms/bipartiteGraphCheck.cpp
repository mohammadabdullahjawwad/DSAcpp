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

vi gr[100005];
int visited[100005]; // We can have 3 values for this : 0-not visited, 1-visited and in set 1, 2-visited and in set 2
bool oddCycle = 0;

void dfs(int cur, int parent, int color) {
    visited[cur] = color;
    for(auto child : gr[cur]) {
        if(!visited[child]) {
            dfs(child, cur, 3-color); // if color is 2, it'll be 1 and vice versa
        }
        else if(child != parent && color == visited[child]) {
            // backedge and odd length cycle
            oddCycle = 1;
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        gr[x].pub(y);
        gr[y].pub(x);
    }
    dfs(1, 0, 1);
    if(oddCycle) {
        cout << "Not Bipartite" << endl;
    }
    else {
        cout << "Bipartite" << endl;
    }
}

int main() {
    OJ;
    FIO;
    solve();
    return 0;
}