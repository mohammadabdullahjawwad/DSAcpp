#include <iostream>
#include <vector>
using namespace std;

#define pii pair<int ,int>

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

pii staircase(vector<vector<int>> a, int n, int target) {
    int i = 0;
    int j = n - 1;
    while(i < n && j >= 0) {
        if(a[i][j] == target) {
            return {i, j};
        }
        if(a[i][j] > target) {
            j--;
        }
        else {
            i++;
        }
    }
    return {-1, -1};
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    vector<vector<int>> a;
    for(int i=0; i<n; i++) {
        vector<int> v;
        for(int j=0; j<n; j++) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        a.push_back(v);
    }
    int target;
    cin >> target;
    cout << "(" << staircase(a, n, target).first << ", " << staircase(a, n, target).second << ")" << endl;
    return 0;
}