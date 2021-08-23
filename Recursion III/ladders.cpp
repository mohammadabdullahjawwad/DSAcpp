#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int ladder(int n, int k) {
    if(n == 0) {
        return 1;
    }
    if(n < 0) {
        return 0;
    }
    int res = 0;
    for(int i=1; i<=k; i++) {
        res += ladder(n - i, k);
    }
    return res;
}

int main() {
    OJ;
    FIO;
    int n, k;
    cin >> n >> k;
    cout << ladder(n, k) << endl;
    return 0;
}