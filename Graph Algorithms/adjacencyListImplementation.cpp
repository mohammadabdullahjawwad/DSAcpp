#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <climits>
#include <list>
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
    int v;
    // Array of list
    list<int>* l; // Pointer to an array of lists
public:
    Graph(int v) {
        this->v = v;
        l = new list<int>[v];
    }
    void addEdge(int x, int y) { // Bidirectional Edge
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void printAdjList() {
        // Iterate over all vertices
        for(int i=0; i<v; i++) {
            cout << "Vertex" << i << " -> ";
            for(int x : l[i]) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    OJ;
    FIO;
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 2);
    g.printAdjList();
    return 0;
}