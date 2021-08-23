#include <iostream>
#include <string.h>
#include <climits>
#include <map>
#include <list>
#include <queue>
using namespace std;

#define ll long long int
#define MOD 1000000007

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

class Graph {
    list<int>* l;
    int v;
public:
    Graph(int v) {
        this->v = v;
        l = new list<int>[v];
    }
    void addEdge(int x, int y) {
        // Directed Graph
        l[x].push_back(y);
    }
    void topologicalSort() {
        // Indegrees of all nodes (vertices)
        int* indegree = new int[v];
        // Initialising indegrees of all nodes as 0
        for(int i=0; i<v; i++) {
            indegree[i] = 0;
        }
        // Update indegrees by traversing
        for(int i=0; i<v; i++) {
            for(auto y : l[i]) {
                indegree[y]++;
            }
        }
        // Apply BFS
        queue<int> q;
        // Find nodes with zero degree and insert in queue
        for(int i=0; i<v; i++) {
            if(!indegree[i]) {
                q.push(i);
            }
        }
        // Start removing elements from queue
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";
            // Iterate over neighbors of node & decrement their degree
            for(auto nbr : l[node]) {
                indegree[nbr]--;
                if(!indegree[nbr]) {
                    q.push(nbr);
                }
            }
        }
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
    g.topologicalSort();
    return 0;
}