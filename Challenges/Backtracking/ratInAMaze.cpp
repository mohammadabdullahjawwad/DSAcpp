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

bool ratMaze(vector<vector<char>>& maze, vector<vector<int>>& solution, int i, int j, int n, int m) {
    // Base Case
    if(i == n && j == m) {
        solution[n][m] = 1;
        // Print the solution path
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=m; j++) {
                cout << solution[i][j] << " ";
            }
            cout << endl;
        } 
        return true;
    }
    // If rat goes out of the maze
    if(i > n || j > m) {
        return false;
    }
    // If the cell is blocked
    if(maze[i][j] == 'X') {
        return false;
    }
    // Assuming solution exists through current cell
    solution[i][j] = 1;

    // Recursive Case
    bool Right = ratMaze(maze, solution, i, j + 1, n, m);
    bool Down;
    if(Right == false) {
        Down = ratMaze(maze, solution, i + 1, j, n, m);
    }

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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> maze(n, vector<char>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> maze[i][j];
        }
    }
    vector<vector<int>> solution(n, vector<int>(m, 0));
    bool ans = ratMaze(maze, solution, 0, 0, n - 1, m - 1);
    if(!ans) {
        cout << -1 << endl;
    }
    return 0;
}