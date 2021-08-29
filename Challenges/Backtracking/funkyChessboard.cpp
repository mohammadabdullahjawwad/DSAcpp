#include <iostream>
#include <vector>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int covered = 0;

void funky(vector<vector<int>>& a, int r, int c, int n, int count) {
    if(r < 0 || r >= n || c < 0 || c >= n || a[r][c] == 0) {
        return;
    }
    a[r][c] = 0;
    covered = max(covered, count + 1);
    funky(a, r - 1, c - 2, n, count + 1);
    funky(a, r + 1, c - 2, n, count + 1);
    funky(a, r - 1, c + 2, n, count + 1);
    funky(a, r + 1, c + 2, n, count + 1);
    funky(a, r - 2, c - 1, n, count + 1);
    funky(a, r - 2, c + 1, n, count + 1);
    funky(a, r + 2, c - 1, n, count + 1);
    funky(a, r + 2, c + 1, n, count + 1);
    a[r][c] = 1;
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    int total = 0;
    vector<vector<int>> a(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            if(a[i][j]) {
                total++;
            }
        }
    }
    funky(a, 0, 0, n, 0);
    cout << total - covered << endl;
    return 0;
}