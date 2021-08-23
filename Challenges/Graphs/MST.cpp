#include <iostream>
#include <vector>
#include <queue>
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
    vector<pii>* l; // Adjacency list
    int v;
public:
    Graph(int n) {
        v = n;
        l = new vector<pii>[n];
    }
    void addEdge(int x, int y, int w) {
        l[x].pub({y, w});
        l[y].pub({x, w});
    }
    int prismMST() {
        priority_queue<pii, vector<pii>, greater<pii>> q; // min priority_queue
        bool* visited = new bool[v]{0}; // denotes whether a node has been included in the MST or not
        int ans = 0;
        q.push({0, 0}); // {weight, node}
        while(!q.empty()) {
            // Pick the edge with minimum weight
            auto best = q.top();
            q.pop();
            int weight = best.first;
            int to = best.second;
            if(visited[to]) {
                // discard the edge and continue
                continue;
            }
            ans += weight;
            visited[to] = 1;
            // add new edges to queue
            for(auto x : l[to]) {
                if(!visited[x.first]) {
                    q.push({x.second, x.first});
                }
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
        g.addEdge(x, y, w);
    }
    cout << g.prismMST() << endl;
    return 0;
}