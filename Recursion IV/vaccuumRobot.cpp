#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <cmath>
#include <map>
#include <list>
#include <stack>
#include <queue>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int cleanRoomBattery(vector<vector<bool>> floorPlan, int battery) {
    int m = floorPlan.size();
    int n = floorPlan[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    while(battery) {
        vis[0][0] = true;
        
    }
}

int main() {
    OJ;
    FIO;
    
    return 0;
}