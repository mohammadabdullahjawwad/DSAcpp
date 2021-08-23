#include<iostream>
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
    int m, n;
    cin >> m >> n;
    int a[m][n];
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }
    int startRow = 0, endRow = m-1;
    int startColumn = 0, endColumn = n-1;
    while(startRow <= endRow && startColumn <= endColumn) {
        for(int i=startRow; i<=endRow; i++) {
            cout << a[i][startColumn] << ", ";
        }
        startColumn++;
        for(int j=startColumn; j<=endColumn; j++) {
            cout << a[endRow][j] << ", ";
        }
        endRow--;
        if(endRow > startRow) {
            for(int i=endRow; i>=startRow; i--) {
                cout << a[i][endColumn] << ", ";
            }
            endColumn--;
        }
        if(startColumn < endColumn) {
            for(int j=endColumn; j>=startColumn; j--) {
                cout << a[startRow][j] << ", ";
            }
            startRow++;
        }
    }
    cout << "END" << endl;
	return 0;
}





// All tcs not passed using the code below
// int main() {
//     OJ;
//     FIO;
//     int m, n;
//     cin >> m >> n;
//     int a[10][10];
//     for(int i=0; i<m; i++) {
//         for(int j=0; j<n; j++) {
//             cin >> a[i][j];
//         }
//     }
//     int startRow = 0;
//     int endRow = m-1;
//     int startCol = 0;
//     int endCol = n-1;
//     while(startRow<=endRow && startCol<=endCol) {
//         for(int i=startRow; i<=endRow; i++) {
//             cout << a[i][startCol] << ", ";
//         }
//         startCol++;
//         for(int i=startCol; i<=endCol; i++) {
//             cout << a[endRow][i] << ", ";
//         }
//         endRow--;
//         if(startCol < endCol) {
//             for(int i=endRow; i>=startRow; i--) {
//                 cout << a[i][endCol] << ", ";
//             }
//             endCol--;
//         }
//         if(startRow < endRow) {
//             for(int i=endCol; i>=startCol; i--) {
//                 cout << a[startRow][i] << ", ";
//             }
//             startRow++;
//         }
//     }
//     cout << "END";
// 	return 0;
// }