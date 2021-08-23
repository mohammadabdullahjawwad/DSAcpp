#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int powerBitmasking(int a, int n) { // O(logN)
    int ans = 1;
    while(n > 0) {
        int lbit = (n & 1);
        if(lbit) {
            ans *= a;
        }
        a *= a;
        n >>= 1;
    }
    return ans;
}

int main() {
    OJ;
    FIO;
    int a, n;
    cin >> a >> n;
    cout << powerBitmasking(a, n) << endl;
    return 0;
}
