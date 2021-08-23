#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

bool isValid(int board[10][10], int i, int j, int n) {
    // Checking for column
    for(int row=0; row<i; row++) {
        if(board[row][j] == 1) {
            return false;
        }
    }
    // Checking for left diagonal
    int x = i;
    int y = j;
    while(x >= 0 && y >= 0) {
        if(board[x][y] == 1) {
            return false;
        }
        x--;
        y--;
    }
    // Checking for right diagonal
    x = i;
    y = j;
    while(x >= 0 && y < n) {
        if(board[x][y] == 1) {
            return false;
        }
        x--;
        y++;
    }
    return true;
}

int nQueen(int board[10][10], int i, int n) {
    // Base Case
    if(i == n) {
        return 1;
    }
    // Recursive Case
    int cnt = 0;
    for(int j=0; j<n; j++) {
        if(isValid(board, i, j, n)) {
            board[i][j] = 1;
            cnt += nQueen(board, i + 1, n);
            board[i][j] = 0;
        }
    }
    return cnt;
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    int board[10][10] = {0};
    cout << nQueen(board, 0, n) << endl;
    return 0;
}

// In this question, we return the number of possible configurations