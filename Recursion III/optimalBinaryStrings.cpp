#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int binaryString(int n) {
    if(n == 0 || n == 1) {
        return n + 1;
    }
    return binaryString(n - 1) + binaryString(n - 2);
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    cout << binaryString(n) << "\n";
    return 0;
}