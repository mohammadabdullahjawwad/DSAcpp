#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

// W, N, E, S
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int r, c;

void printMatrix(char mat[][100]) {
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cout << mat[i][j];
        }
        cout << endl;
    }
}

// ch - character to be read
// color - character to be added
void floodFill(char mat[][100], int i, int j, char ch, char color) {
    // Base Case - Matrix Bounds
    if(i<0 || j<0 || i>=r || j>=c) {
        return;
    }
    // Figure Boundary Condition
    if(mat[i][j] != ch) {
        return;
    }
    // Recursive Call
    mat[i][j] = color;
    // printMatrix(mat);
    // cout << endl;
    for(int k=0; k<4; k++) { // 4 directions
        floodFill(mat, i+dx[k], j+dy[k], ch, color);
    }
}

int main() {
    OJ;
    FIO;
    cin >> r >> c;
    char input[25][100];
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            cin >> input[i][j];
        }
    }
    printMatrix(input);
    cout << "\n\n\n";
    floodFill(input, 8, 15, '.', 'r');
    floodFill(input, 0, 0, '.', ':');
    printMatrix(input);
    return 0;
}