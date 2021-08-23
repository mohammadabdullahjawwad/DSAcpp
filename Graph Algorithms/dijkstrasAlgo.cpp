#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <climits>
#include <unordered_map>
#include <list>
#include <set>
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

template<typename T>
class Graph {
    unordered_map<T, list<pair<T, int>>> m;
public:
    void addEdge(T u, T v, int dist, bool bidir=true) {
        m[u].pub(mp(v, dist));
        if(bidir) {
            m[v].pub(mp(u, dist));
        }
    }
    void printAdj() {
        for(auto j : m) {
            cout << j.first << " -> ";
            for(auto k : j.second) {
                cout << "(" << k.first << ", " << k.second << ") ";
            }
            cout << endl;
        }
    }
    void dijkstra(T src) {
        unordered_map<T, int> dist;
        // Initially set all distances to infinity
        for(auto j : m) {
            dist[j.first] = INT_MAX;
        }
        // Set to find out the node with minimum distance
        set<pair<int, T>> s; // By default set is sorted according to first parameter
        dist[src] = 0;
        s.insert(mp(0, src));
        while(!s.empty()) {
            // Find the pair at the front
            auto p = *(s.begin()); // since s.begin() is a pointer
            T node = p.second;
            int nodeDist = p.first;
            s.erase(s.begin());
            // Iterate over neighbours of the (current) node
            for(auto childPair : m[node]) {
                if(nodeDist + childPair.second < dist[childPair.first]) {
                    // In set updation is not possible, hence remove old pair and insert new pair
                    T dest = childPair.first;
                    auto f = s.find(mp(dist[dest], dest));
                    if(f != s.end()) {
                        s.erase(f);
                    }
                    dist[dest] = nodeDist + childPair.second;
                    s.insert(mp(dist[dest], dest));
                }
            }
        }
        // Print distances to all other nodes from src
        for(auto d : dist) {
            cout << d.first << " : " << d.second << endl;
        }
    }
};

int main() {
    OJ;
    FIO;
    Graph<int> g;
    int e;
    cin >> e;
    while(e--) {
        int x, y, dis;
        cin >> x >> y >> dis;
        g.addEdge(x, y, dis);
    }
    // g.printAdj();
    g.dijkstra(1);
    return 0;
}