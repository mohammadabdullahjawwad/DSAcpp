#include <iostream>
#include <climits>
#include <queue>
using namespace std;

typedef pair<int, pair<int, int>> custom;

int kthSmallestElement(int *a, int r, int c, int k) {
    // Pre requisite condition : 0 <= k <= r*c
    if(k <=0 || k >= r*c) {
        return INT_MAX;
    }
    // Creating a min heap
    priority_queue<custom, vector<custom>, greater<custom>> p;
    // Add first row in heap
    for(int i=0; i<c; i++) {
        p.push({*((a+0*c)+i), {0, i}}); // *((a+0*c)+i) is written for a[0][i]
    }
    custom result; // Stores the result to be returned
    while(k--) { // kth smallest number
        result = p.top();
        p.pop();
        int x = result.second.first;
        int y = result.second.second;
        if(x+1 < r) { // The present row can be at max last row
            p.push({*((a+(x+1)*c)+y), {x+1, y}}); // *((a+(x+1)*c)+y) is written for a[x+1][y]
        }
    }
    return result.first;
}

int main() {
    int r, c;
    cin >> r >> c;
    int a[r][c];
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> a[i][j];
        }
    }
    int k;
    cin >> k;
    int ans = kthSmallestElement((int *)a, r, c, k);
    if(ans == INT_MAX) {
        cout << "ERROR" << endl;
    }
    else {
        cout << ans << endl;
    }
    return 0;
}