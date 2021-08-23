#include <iostream>
using namespace std;

#define ll long long int

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int clearRangeIToJ(int n, int i, int j) {
    int a = (-1 << j + 1);
    int b = (1 << i) - 1;
    int mask = a | b;
    return n & mask;
}

int replaceBits(int n, int m, int i, int j) {
    int clearedN = clearRangeIToJ(n, i, j);
    return clearedN | (m << i);
}

int main() {
    OJ;
    FIO;
    int n, m, i, j;
    cin >> n >> m >> i >> j;
    cout << replaceBits(n, m, i, j) << endl;
    return 0;
}