#include <iostream>
#include <list>
using namespace std;

#define pii pair<int ,int>
#define pub push_back
#define mp make_pair

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

class Graph {
    int v;
    list<pii> l; // We create edge list and not adjacency list
public:
    Graph(int v) {
        this->v = v;
    }
    void addEdge(int u, int v) {
        l.pub(mp(u, v));
    }
    // DSU find fn
    int find(int i, int* parent) {
        if(parent[i] == -1) {
            return i;
        }
        // Path Compression
        return parent[i] = find(parent[i], parent);
    }
    // DSU union fn [union is a keyword in cpp]
    void unionSet(int i, int j, int* parent, int* rank) {
        int s1 = find(i, parent);
        int s2 = find(j, parent);
        // Union by Rank
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
    bool containsCycle() {
        // We will use DSU logic here
        int* parent = new int[v];
        int* rank = new int[v];
        for(int i=0; i<v; i++) {
            parent[i] = -1;
            rank[i] = 1; // Initially rank of each node is 1
        }
        for(auto edge : l) {
            int i = edge.first;
            int j = edge.second;
            int s1 = find(i, parent);
            int s2 = find(j, parent);
            if(s1 != s2) {
                unionSet(s1, s2, parent, rank);
            }
            else {
                return true;
            }
        }
        delete[] parent;
        delete[] rank;
        return false;
    }
};

int main() {
    OJ;
    FIO;
    int v;
    cin >> v;
    Graph g(v);
    int e;
    cin >> e;
    while(e--) {
        int x, y;
        cin >> x >> y;
        g.addEdge(x, y);
    }
    cout << g.containsCycle() << endl;
    return 0;
}