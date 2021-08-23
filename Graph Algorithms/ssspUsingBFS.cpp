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
        l[x].pub(y);
        l[y].pub(x);
    }
    void bfs(T src) {
        map<T, int> dis;
        queue<T> q;
        // All nodes will be at a distance of infinity initially
        for(auto nodePair : l) {
            T node = nodePair.first;
            dis[node] = INT_MAX;
        }
        q.push(src);
        dis[src] = 0;
        while(!q.empty()) {
            T node = q.front();
            q.pop();
            for(int nbr : l[node]) {
                if(dis[nbr] == INT_MAX) {
                    q.push(nbr);
                    dis[nbr] = dis[node] + 1;
                }
            }
        }
        // Print dis of every node from src
        for(auto nodePair : l) {
            T node = nodePair.first;
            int d = dis[node];
            cout << node << " : " << d << endl;
        }
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
    g.bfs(0);
    return 0;
}