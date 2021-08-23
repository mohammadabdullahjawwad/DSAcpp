#include <iostream>
using namespace std;
int tiling(int n) {
    if(n == 1 || n == 2 || n == 3) {
        return 1;
    } else if(n == 4) {
        return 2;
    }
    return tiling(n-1) + tiling(n-4);
}

int main() {
    int n;
    cin >> n;
    cout << tiling(n) << endl;
    return 0;
}