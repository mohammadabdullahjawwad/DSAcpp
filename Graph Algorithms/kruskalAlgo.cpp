#include <iostream>
#include <vector>
#include <algorithm>
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

class DSU {
    int* parent;
    int* rank;
public:
    DSU(int n) {
        parent = new int[n];
        rank = new int[n];
        for(int i=0; i<n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
    int find(int i) {
        if(parent[i] == -1) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    void unite(int x, int y) {
        int s1 = find(x);
        int s2 = find(y);
        if(s1 != s2) {
            if(rank[s1] < rank[s2]) {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class Graph {
    vector<vi> edgeList; // edge list implementation
    int v;
public:
    Graph(int v) : v(v) {};
    void addEdge(int x, int y, int w) {
        edgeList.pub({w, x, y}); // we put w (weight) first because during sorting, it wil automatically sort according to 0th index, since we need to sort edges according to weights
    }
    int kruskalMST() {
        // 1. Sort edges according to weights
        sort(edgeList.begin(), edgeList.end());
        DSU s(v);
        int ans = 0;
        for(auto edge : edgeList) {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];
            // 2. Take the edge in MST if it doesn't form a cycle
            if(s.find(x) != s.find(y)) {
                s.unite(x, y);
                ans += w;
            }
        }
        return ans;
    }
};

int main() {
    OJ;
    FIO;
    int v, e;
    cin >> v >> e;
    Graph g(v);
    while(e--) {
        int x, y, w;
        cin >> x >> y >> w;
        g.addEdge(x-1, y-1, w); // If input is in 1 based indexing
    }
    cout << g.kruskalMST() << endl;
    return 0;
}