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

vi graph[100005];
vi rev[100005];
vi order;
int visited[100005];
int comp[100005];
// vi in_comp[100005];

void dfs(int cur) {
    visited[cur] = 1;
    for(auto x : graph[cur]) {
        if(!visited[x]) {
            dfs(x);
        }
    }
    order.pub(cur);
}

void dfs_reverse(int cur, int color) {
    comp[cur] = color;
    // in_comp[color].pub(cur);
    visited[cur] = 1;
    for(auto x : rev[cur]) {
        if(!visited[x]) {
            dfs_reverse(x, color);
        }
    }
}

int main() {
    OJ;
    FIO;
    int n, m;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].pub(y);
        rev[y].pub(x);
    }
    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }
    memset(visited, 0, sizeof(visited));
    int color = 1;
    for(int i=n; i>0; i--) {
        if(!visited[order[i]]) {
            dfs_reverse(order[i], color);
            color++;
        }
    }
    for(int i=1; i<=n; i++) {
        cout << i << " -> " << comp[i] << endl;
    }
    return 0;
}