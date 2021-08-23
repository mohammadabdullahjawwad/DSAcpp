#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

bool ratMaze(char maze[][10],int solution[][10], int i, int j, int m, int n) {
    // Base Case
    if(i == m && j == n) {
        solution[m][n] = 1;
        // Print the solution path
        for(int i=0; i<=m; i++) {
            for(int j=0; j<=n; j++) {
                cout << solution[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }
    // If rat goes out of the maze
    if(i > m || j > n) {
        return false;
    }
    // If the cell is blocked
    if(maze[i][j] == 'X') {
        return false;
    }
    // Assuming solution exists through current cell
    solution[i][j] = 1;

    // Recursive Case
    bool Right = ratMaze(maze, solution, i, j + 1, m, n);
    bool Down = ratMaze(maze, solution, i + 1, j, m, n);

    // Backtracking
    solution[i][j] = 0;

    if(Right || Down) {
        return true;
    }
    return false;
}

int main() {
    OJ;
    FIO;
    int m, n;
    cin >> m >> n;
    char maze[10][10];
    // char maze[10][10] = {
    //     "000X",
    //     "00X0",
    //     "00X0",
    //     "X000"
    // };
    for(int i = 0; i < m; i++) {
        cin >> maze[i];
    }
    int solution[10][10] = {0};
    bool ans = ratMaze(maze, solution, 0, 0, m - 1, n - 1);
    if(!ans) {
        cout << "No path exists!" << endl;
    }
    return 0;
}