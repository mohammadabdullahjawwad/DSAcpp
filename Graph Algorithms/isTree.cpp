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
public:
    Graph(int v) {
        this->v = v;
        l = new list<int>[v];
    }
    void addEdge(int x, int y) {
        // Undirected Graph
        l[x].pub(y);
        l[y].pub(x);
    }
    bool isTree() {
        bool* visited = new bool[v];
        int* parent = new int[v];
        queue<int> q;
        for(int i=0; i<v; i++) {
            visited[i] = false;
            parent[i] = i;
        }
        int src = 0;
        q.push(src);
        visited[src] = true;
        // Pop nodes one by one from queue and visit their neighbours
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(int nbr : l[node]) {
                if(visited[nbr] && parent[node] != nbr) {
                    return false;
                }
                else if(!visited[nbr]) {
                    visited[nbr] = true;
                    parent[nbr] = node;
                    q.push(nbr);
                }
            }
        }
        return true;
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
    if(g.isTree()) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}