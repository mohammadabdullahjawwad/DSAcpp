#include <iostream>
using namespace std;

bool ratCheese(char maze[][11],int solution[][11], int i, int j, int n, int m) {
    // Base Case
    if((i == n) && (j == m)) {
        if(maze[i][j] == 'X') {
            return false;
        }
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
    if((i < 0) || (i > n) || (j < 0) || (j > m)) {
        return false;
    }
    // If the cell is blocked
    if(maze[i][j] == 'X') {
        return false;
    }
    // Assuming solution exists through current cell
    solution[i][j] = 1;

    // Recursive Case
    bool Left, Right, Up, Down;
    Left = Right = Up = Down = false;
    if(solution[i][j-1] == 0) {
        Left = ratCheese(maze, solution, i, j-1, n, m);
    } 
    if(Left == false && solution[i][j+1] == 0) {
        Right = ratCheese(maze, solution, i, j+1, n, m);
    }
    if(Left == false && Right == false && solution[i-1][j] == 0) {
        Up = ratCheese(maze, solution, i-1, j, n, m);
    }
    if(Left == false && Right == false && Up == false && solution[i+1][j] == 0) {
        Down = ratCheese(maze, solution, i+1, j, n, m);
    }
    // Backtracking
    solution[i][j] = 0;

    if(Left || Right || Up || Down) {
        return true;
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    char maze[11][11];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> maze[i][j];
        }
    }
    int solution[11][11] = {0};
    bool ans = ratCheese(maze, solution, 0, 0, n-1, m-1);
    if(!ans) {
        cout <<  "NO PATH FOUND" << endl;
    }
    return 0;
}