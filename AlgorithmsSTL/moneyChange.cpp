#include <iostream>
#include <algorithm>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

bool compare(int a, int b) {
    return a <= b; // return a value <= money
}

void solve() {
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int n = sizeof(coins) / sizeof(int);
    int money;
    cin >> money;
    while(money) {
        int lb = lower_bound(coins, coins + n, money, compare) - coins - 1;
        int used = coins[lb];
        cout << used << " ";
        money -= used;
    }
    cout << endl;
}

int main() {
    OJ;
    FIO;
    // ll t;
    // cin >> t;
    // while(t--) {
        solve();
    // }
    return 0;
}