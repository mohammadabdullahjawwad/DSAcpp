#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int maxSumSubmatrix(vector<vector<int>> a, int n, int m) {
    // Columnwise addition first
    for(int i=n-1; i>=0; i--) {
        for(int j=m-2; j>=0; j--) { // rightmost column doesn't add anything
            a[i][j] += a[i][j+1];
        }
    }
    // Rowwise addition
    for(int j=m-1; j>=0; j--) {
        for(int i=n-2; i>=0; i--) { // lowermost row doesn't add anything
            a[i][j] += a[i+1][j];
        }
    }
    int result = INT_MIN;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            result = max(result, a[i][j]);
        }
    }
    return result;
}

int main() {
    OJ;
    FIO;
    int r, c;
    cin >> r >> c;
    vector<vector<int>> a(r, vector<int>(c));
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> a[i][j];
        }
    }
    cout << maxSumSubmatrix(a, r, c) << endl;
    return 0;
}