#include <iostream>
#include <list>
#include <unordered_map>
#include <cstring>
using namespace std;

#define pub push_back
#define pob pop_back
#define mp make_pair

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

class Graph {
    // Adj list
    unordered_map<string, list<pair<string, int>>> l;
public:
    void addEdge(string x, string y, bool bi, int weight) {
        l[x].pub(mp(y, weight));
        if(bi) {
            l[y].pub(mp(x, weight));
        }
    }
    void printAdjList() {
        // Iterate over all keys in the map
        for(auto p : l) {
            string vertex = p.first;
            list<pair<string, int>> nbr = p.second;
            cout << vertex << " : ";
            for(auto n : nbr) {
                string end = n.first;
                int dis = n.second;
                cout << "(" << end << ", " << dis << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    OJ;
    FIO;
    Graph g;
    g.addEdge("A", "B", true, 20);
    g.addEdge("B", "D", true, 40);
    g.addEdge("A", "C", true, 10);
    g.addEdge("C", "D", true, 40);
    g.addEdge("A", "D", false, 50);
    g.printAdjList();
    return 0;
}