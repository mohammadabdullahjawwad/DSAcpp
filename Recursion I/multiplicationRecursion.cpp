#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int multiply(int a, int b) {
    if(a > 0 && b < 0) {
        return multiply(b, a);
    }
    if(a < 0 && b < 0) {
        return multiply(-a, -b);
    }
    if(a > b) {
        return multiply(b, a);
    }
    if(b != 0) {
        return a + multiply(a, b - 1);
    }
    return 0;
}

int main() {
    OJ;
    FIO;
    int a, b;
    cin >> a >> b;
    cout << multiply(a, b) << endl;
    return 0;
}