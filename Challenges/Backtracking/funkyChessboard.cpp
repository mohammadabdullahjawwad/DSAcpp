#include <iostream>
using namespace std;

int covered = 0;

void funky(int a[][11], int r, int c, int count) {
    if((r < 0) || (r > 10) || (c < 0) || (c > 10) || (a[r][c] == 0)) {
        return;
    }
    a[r][c] = 0;
    covered = max(covered, count+1);
    funky(a, r-1, c-2, count+1);
    funky(a, r-1, c+2, count+1);
    funky(a, r+1, c-2, count+1);
    funky(a, r+1, c+2, count+1);
    funky(a, r-2, c-1, count+1);
    funky(a, r-2, c+1, count+1);
    funky(a, r+2, c-1, count+1);
    funky(a, r+2, c+1, count+1);
    a[r][c] = 1;
}

int main() {
    int n;
    cin >> n;
    int sum = 0;
    int a[11][11] = {0};
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> a[i][j];
            if(a[i][j]) {
                sum++;
            }
        }
    }
    funky(a, 0, 0, 0);
    cout << sum - covered << endl;
    return 0;
}