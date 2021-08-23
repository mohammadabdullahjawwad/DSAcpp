#include<iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void spiralClockwise(int a[1000][1000], int m, int n) {
    int startRow = 0, endRow = m-1;
    int startColumn = 0, endColumn = n-1;
    while(startRow <= endRow && startColumn <= endColumn) {
        for(int j=startColumn; j<=endColumn; j++) {
            cout << a[startRow][j] << " ";
        }
        startRow++;
        for(int i=startRow; i<=endRow; i++) {
            cout << a[i][endColumn] << " ";
        }
        endColumn--;
        if(endRow > startRow) {
            for(int j=endColumn; j>=startColumn; j--) {
                cout << a[endRow][j] << " ";
            }
            endRow--;
        }
        if(startColumn < endColumn) {
            for(int i=endRow; i>=startRow; i--) {
                cout << a[i][startColumn] << " ";
            }
            startColumn++;
        }
    }
    cout << endl;
}

int main() {
    OJ;
    FIO;
    int m, n;
    cin >> m >> n;
    int a[1000][1000];
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }
    spiralClockwise(a, m, n);
	return 0;
}