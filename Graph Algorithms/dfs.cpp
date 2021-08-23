#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <climits>
#include <list>
#include <queue>
#include <map>
using namespace std;

#define vi vector<int>
#define pii pair<int ,int>
#define all(v) v.begin(), v.end()
#define pub push_back
#define pof pop_front
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

template<typename T>
class Graph {
    map<T, list<T>> l;
    void helper(T src, map<T, bool>& visited) {
        // Recursive function that will traverse the graph
        cout << src << " ";
        visited[src] = true;
        // Go to all non-visited neighbour of src
        for(T nbr : l[src]) {
            if(!visited[nbr]) {
               helper(nbr, visited);
            }
        }
    }
public:
    void addEdge(int x, int y) {
        l[x].pub(y);
        l[y].pub(x);
    }
    void dfs(T src) {
        map<T, bool> visited;
        // Mark all nodes not visited initially
        for(auto p : l) {
            T node = p.first;
            visited[node] = false;
        }
        // Call helper function
        helper(src, visited);
    }
};

int main() {
    OJ;
    FIO;
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.dfs(0);
    return 0;
}