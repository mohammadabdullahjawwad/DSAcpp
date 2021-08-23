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

bool nQueen(int board[10][10], int i, int n) {
    // Base Case
    if(i == n) {
        // Print the configuration
        for(int k=0; k<n; k++) {
            for(int j=0; j<n; j++) {
                if(board[k][j] == 1) {
                    cout << "Q ";
                }
                else {
                    cout << "_ ";
                }
            }
            cout << endl;
        }
        cout << endl;
        return true; //  If we want to find all possible configurations, we can return false instead of true. This will enforce control to search for more configurations, and eventually we will get all configurations.
    }
    // Recursive Case
    for(int j=0; j<n; j++) {
        if(isValid(board, i, j, n)) {
            board[i][j] = 1;
            bool nextQueenPossible = nQueen(board, i + 1, n);
            if(nextQueenPossible) {
                return true;
            }
            board[i][j] = 0;
        }
    }
    return false;
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    int board[10][10] = {0};
    nQueen(board, 0, n);
    return 0;
}