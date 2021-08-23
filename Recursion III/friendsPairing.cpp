#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int friends(int n) {
    if(n == 0 || n == 1) {
        return 1;
    }
    return friends(n - 1) + (n - 1) * friends(n - 2); // Choose 1 out of (n - 1) people remaining in (n-1)C(1) i.e. (n - 1) ways
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    cout << friends(n) << endl;
    return 0;
}