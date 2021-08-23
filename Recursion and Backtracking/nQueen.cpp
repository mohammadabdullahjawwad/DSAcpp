#include <iostream>
using namespace std;

bool isValid(int board[][16], int i, int j, int n) {
    // Checking for column
    for(int row=0; row<i; row++) {
        if(board[row][j] == 1) {
            return false;
        }
    }
    // Checking for left diagonal
    int x = i;
    int y = j;
    while((x >= 0) && (y >= 0)) {
        if(board[x][y] == 1) {
            return false;
        }
        x--;
        y--;
    }
    // Checking for right diagonal
    x = i;
    y = j;
    while((x >= 0) && (y < n)) {
        if(board[x][y] == 1) {
            return false;
        }
        x--;
        y++;
    }
    return true;
}

bool nQueen(int board[][16], int i, int n) {
    // Base Case
    if(i == n) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }
    // Recursive Case
    for(int j=0; j<n; j++) {
        if(isValid(board, i, j, n)) {
            board[i][j] = 1;
            bool nextQueenPossible = nQueen(board, i+1, n);
            if(nextQueenPossible) {
                return true;
            }
            board[i][j] = 0;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    int board[][16] = {0};
    nQueen(board, 0, n);
    return 0;
}
