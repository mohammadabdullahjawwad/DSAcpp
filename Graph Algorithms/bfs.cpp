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
public:
    void addEdge(int x, int y) {
        // Assuming edges are bidirectional
        l[x].pub(y);
        l[y].pub(x);
    }
    void bfs(T src) {
        map<T, int> visited;
        queue<T> q;
        q.push(src);
        visited[src] = true;
        while(!q.empty()) {
            T node = q.front();
            q.pop();
            cout << node << " ";
            for(int nbr : l[node]) {
                if(!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }
};

int main() {
    OJ;
    FIO;
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.bfs(0);
    return 0;
}