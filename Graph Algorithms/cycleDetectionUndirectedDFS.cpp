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

class Graph {
    list<int>* l;
    int v;
    bool helper(int node, bool* visited, int parent) {
        visited[node] = true;
        for(int nbr : l[node]) {
            // Case 1 : nbr not visited
            if(!visited[nbr]) {
                bool cycle = helper(nbr, visited, node);
                if(cycle) {
                    return true;
                }
            }
            // Case 2 : nbr visited, but nbr != parent
            else if(nbr != parent) {
                return true;
            }
        }
        return false;
    }
public:
    Graph(int v) {
        this->v = v;
        l = new list<int>[v];
    }
    void addEdge(int x, int y, bool directed = true) {
        l[x].pub(y);
        // In case of undirected Graph
        if(!directed) {
            l[y].pub(x);
        }
    }
    bool containsCycle() {
        // Check for cycle in directed graph
        bool* visited = new bool[v];
        for(int i=0; i<v; i++) {
            visited[i] = false;
        }
        return helper(0, visited, -1);
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
    while (e--) {
        int x, y;
        cin >> x >> y;
        g.addEdge(x, y);
    }
    if(g.containsCycle()) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}