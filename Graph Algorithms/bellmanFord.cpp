#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define vi vector<int>
#define pub push_back

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

vi bellmanFord(int n, int src, vector<vi> edge) {
    vi dis(n+1, INT_MAX); // Since we are using 1 based indexing
    dis[src] = 0;
    // Relax all edges n-1 times
    for(int i=0; i<n-1; i++) {
        for(auto x : edge) {
            int from = x[0], to = x[1], weight = x[2];
            if(dis[from] != INT_MAX && dis[to] > dis[from] + weight) {
                dis[to] = dis[from] + weight;
            }
        }
    }
    // Negative weight cycle check
    for(auto x : edge) {
        int from = x[0], to = x[1], weight = x[2];
        if(dis[from] != INT_MAX && dis[to] > dis[from] + weight) {
            cout << "Negative weight cycle" << endl;
            exit(0);
        }
    }
    return dis;
}

int main() {
    OJ;
    FIO;
    int v, e;
    cin >> v >> e;
    vector<vi> edge;
    for(int i=0; i<e; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        edge.pub({x, y, w});
    }
    vi dis = bellmanFord(v, 1, edge);
    for(int i=1; i<=v; i++) {
        cout << dis[i] << endl;
    }
    return 0;
}