#include <iostream>
#include <cmath>
using namespace std;

bool isPossible(int matrix[][9], int i, int j, int n, int number) {
    // Row and column check
    for(int x=0; x<n; x++) {
        if((matrix[i][x] == number) || (matrix[x][j] == number)) {
            return false;
        }
    }
    // Submatrix check
    int rn = sqrt(n);
    int sx = (i/rn)*rn;
    int sy = (j/rn)*rn;
    for(int x=sx; x<sx+rn; x++) {
        for(int y=sy; y<sy+rn; y++) {
            if(matrix[x][y] == number) {
                return false;
            }
        }
    }
    return true;
}

bool solve(int matrix[][9], int i, int j, int n) {
    // Base Case
    if(i == n) {
        // Print the matrix
        for(int x=0; x<n; x++) {
            for(int y=0; y<n; y++) {
                cout << matrix[x][y] << " ";
            }
            cout << endl;
        }
        return true;
    }
    // Reached the end of row
    if(j == n) {
        return solve(matrix, i+1, 0, n);
    }
    // Skip the pre-filled cells
    if(matrix[i][j] != 0) {
        return solve(matrix, i, j+1, n);
    }

    // Recursive Case
    // Fill the current cell with possible options
    for(int number=1; number<=n; number++) {
        if(isPossible(matrix, i, j, n, number)) {
            matrix[i][j] = number;
            bool solveCheck = solve(matrix, i, j+1, n);
            if(solveCheck) {
                return true;
            }
        }
    }
    // Backtracking
    matrix[i][j] = 0;
    return false;
}

int main() {
    int n;
    cin >> n;
    int matrix[9][9];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> matrix[i][j];
        }
    }
    solve(matrix, 0, 0, n);
    return 0;
}