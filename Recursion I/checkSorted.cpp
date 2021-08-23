#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

bool isSorted(int* a, int n) {
    if(n == 0 || n == 1) {
        return true;
    }
    if(a[0] < a[1] && isSorted(a + 1, n - 1)) {
        return true;
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    int* a = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << isSorted(a, n) << endl;
}

int main() {
    OJ;
    FIO;
    solve();
    return 0;
}