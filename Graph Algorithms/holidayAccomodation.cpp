#include <iostream>
#include <list>
using namespace std;

#define pii pair<int ,int>
#define pub push_back

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

class Graph {
    int v;
    list<pii> *l;
public:
    Graph(int v) {
        this->v = v;
        l = new list<pii>[v];
    }
    void addEdge(int x, int y, int z) {
        l[x].pub({y, z});
        l[y].pub({x, z});
    }
    int DFShelper(int node, bool* visited, int* count, int &ans) {
        // Mark node as visited
        visited[node] = true;
        count[node] = 1;
        for(auto nbrPair:l[node]) {
            int nbr = nbrPair.first;
            int wt = nbrPair.second;
            if(!visited[nbr]) {
                count[node] += DFShelper(nbr, visited, count, ans);
                int nx = count[nbr];
                int ny = v - nx;
                ans += 2 * min(nx, ny) * wt;
            }
        }
        return count[node];
    }
    int dfs() {
        bool* visited = new bool[v];
        int *count = new int[v]; // Stores count of every node
        for(int i=0; i<v; i++) {
            visited[i] = false;
            count[i] = 0;
        }
        int ans = 0;
        int cnt = DFShelper(0, visited, count, ans);
        return ans;
    }
};

int main() {
    OJ;
    FIO;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        Graph g(n);
        int edges = n-1;
        while(edges--) {
            int x, y, z;
            cin >> x >> y >> z;
            g.addEdge(x-1, y-1, z);
        }
        cout << g.dfs() << endl;
    }
    return 0;
}

// Solution not accepted in spoj - wrong ans