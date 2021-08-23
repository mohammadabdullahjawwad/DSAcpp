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
    map<T, list<T>> l;
public:
    void addEdge(int x, int y) {
        l[x].pub(y);
    }
    int snakesAndLadder(T src, T dest) {
        map<T, int> dis;
        map<T, T> parent;
        queue<T> q;
        // All nodes will be at a distance of infinity initially
        for(auto nodePair : l) {
            T node = nodePair.first;
            dis[node] = INT_MAX;
        }
        q.push(src);
        dis[src] = 0;
        parent[src] = src;
        while(!q.empty()) {
            T node = q.front();
            q.pop();
            for(int nbr : l[node]) {
                if(dis[nbr] == INT_MAX) {
                    q.push(nbr);
                    dis[nbr] = dis[node] + 1;
                    parent[nbr] = node;
                }
            }
        }
        // Print path from dest to src
        T temp = dest;
        while(temp != src) {
            cout << temp << " -> ";
            temp = parent[temp];
        }
        cout << src << endl;
        // Print distance of dest from src
        return dis[dest];
    }
};

int main() {
    OJ;
    FIO;
    int board[37] = {0};
    board[2] = 13; // 15 - 2 = 13
    board[5] = 2;
    board[9] = 18;
    board[17] = -13; // -(17 - 4) = -13
    board[18] = 11;
    board[20] = -14;
    board[24] = -8;
    board[25] = 10;
    board[32] = -2;
    board[34] = -22;
    Graph<int> g;
    for(int i=0; i<36; i++) {
        for(int dice=1; dice<=6; dice++) {
            int j = i + dice;
            j += board[j];
            if(j <= 36) {
                g.addEdge(i, j);
            }
        }
    }
    g.addEdge(36, 36); // In order to add l[36] to map
    cout << g.snakesAndLadder(0, 36) << endl;
    return 0;
}