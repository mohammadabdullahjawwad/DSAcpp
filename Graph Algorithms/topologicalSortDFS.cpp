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
    void helper(T src, map<T, bool>& visited, list<T>& ordering) { // Recursive function that will traverse the graph
        visited[src] = true;
        // Go to all non-visited neighbour of src
        for(T nbr : l[src]) {
            if(!visited[nbr]) {
               helper(nbr, visited, ordering);
            }
        }
        ordering.push_front(src);
    }
public:
    void addEdge(T x, T y) {
        l[x].pub(y);
    }
    void dfs() {
        map<T, bool> visited;
        list<T> ordering;
        // Mark all nodes not visited initially
        for(auto p : l) {
            T node = p.first;
            visited[node] = false;
        }
        for(auto p : l) {
            T node = p.first;
            if(!visited[node]) {
                helper(node, visited, ordering);
            }
        }
        // Print the list (Topological Sort)
        for(auto node : ordering) {
            cout << node << endl;
        }
    }
};

int main() {
    OJ;
    FIO;
    Graph<string> g;
    g.addEdge("Python", "DataPreprocessing");
    g.addEdge("Python", "PyTorch");
    g.addEdge("Python", "ML");
    g.addEdge("DataPreprocessing", "ML");
    g.addEdge("PyTorch", "DL");
    g.addEdge("ML", "DL");
    g.addEdge("DL", "FacialRecognition");
    g.addEdge("DataSet", "FacialRecognition");
    g.dfs();
    return 0;
}