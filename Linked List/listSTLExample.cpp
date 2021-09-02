#include <iostream>
#include <vector>
#include <list>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int main() {
    OJ;
    FIO;
    list<pair<int, int>> *l;
    int v;
    cin >> v;
    l = new list<pair<int, int>>[v];
    int e;
    cin >> e;
    for(int i = 0; i < e; i++) {
        int x, y, wt;
        cin >> x >> y >> wt;
        l[x].push_back({y, wt});
        l[y].push_back(make_pair(x, wt));
    }

    // Print the linked lists
    for(int i = 0; i < v; i++) {
        cout << i << " --> ";
        for(auto xp : l[i]) {
            cout << "(" << xp.first << ", " << xp.second << ") ";
        }
        cout << endl;
    }
    return 0;
}