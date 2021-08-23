#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int decToBin(int n) {
    int ans = 0;
    int p = 1;
    while(n > 0) {
        int lbit = n & 1;
        ans += p * lbit;
        p *= 10;
        n >>= 1;
    }
    return ans;
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    cout << decToBin(n) << endl;
    return 0;
}
