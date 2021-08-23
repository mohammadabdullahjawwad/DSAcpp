#include <bits/stdc++.h>
using namespace std;

#define pub push_back
#define mp make_pair

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

template<typename T>
class Graph {
    unordered_map<T, list<pair<T, pair<int, int>>>> m;
public:
    void addEdge(T u, T v, int train, int flight, bool bidir=true) {
        m[u].pub(mp(v, mp(train, flight)));
        if(bidir) {
            m[v].pub(mp(u, mp(train, flight)));
        }
    }
    void printAdj() {
        for(auto j : m) {
            cout << j.first << " -> ";
            for(auto k : m[j.first]) {
                cout << "{" << k.first << ", (" << k.second.first << ", " << k.second.second << ")} ";
            }
            cout << endl;
        }
    }
    unordered_map<T, int> dijkstra(T src) {
        unordered_map<T, int> fare;
        for(auto j : m) {
            fare[j.first] = INT_MAX;
        }
        set<pair<int, T>> s;
        fare[src] = 0;
        s.insert(mp(0, src));
        while(!s.empty()) {
            auto p = *(s.begin());
            T node = p.second;
            int nodeDist = p.first;
            s.erase(s.begin());
            for(auto childPair : m[node]) {
                if(nodeDist + childPair.second.first < fare[childPair.first]) {
                    T dest = childPair.first;
                    auto f = s.find(mp(fare[dest], dest));
                    if(f != s.end()) {
                        s.erase(f);
                    }
                    fare[dest] = nodeDist + childPair.second.first;
                    s.insert(mp(fare[dest], dest));
                }
            }
        }
        return fare;
    }
    void minCost(T src, T dest) {
        unordered_map<T, int> srcx = dijkstra(src);
        unordered_map<T, int> desty = dijkstra(dest);
        int ans = INT_MAX;
        // Case 1 : 1 flight
        for(auto i : m) {
            for(auto j : m[i.first]) {
                ans = min(ans, srcx[i.first] + j.second.second + desty[j.first]);
            }
        }
        // Case 2 : 0 flights
        ans = min(ans, srcx[dest]);
        cout << ans << endl;
    }
};

int main() {
    OJ;
    FIO;
    Graph<string> g;
    int e;
    cin >> e;
    while(e--) {
        string x, y;
        cin >> x;
        cin >> y;
        int train, flight;
        cin >> train >> flight;
        g.addEdge(x, y, train, flight);
    }
    g.printAdj();
    cout << endl;
    cout << endl;
    cout << endl;
    string src, dest;
    cin >> src >> dest;
    g.minCost(src, dest);
    return 0;
}