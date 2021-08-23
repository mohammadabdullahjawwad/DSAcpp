#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int gcd(int a, int b) { // O(log max(a, b))
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    OJ;
    FIO;
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    return 0;
}