#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int tiling(int n) {
    if(n <= 3) {
        return 1;
    }
    if(n == 4) {
        return 2;
    }
    return tiling(n - 1) + tiling(n - 4);
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    cout << tiling(n) << endl;
    return 0;
}