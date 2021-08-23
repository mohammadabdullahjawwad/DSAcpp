#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b, int hcf) {
    return a * b / hcf;
}

int main() {
    OJ;
    FIO;
    int a, b;
    cin >> a >> b;
    int hcf = gcd(a, b);
    cout << hcf << endl;
    cout << lcm(a, b, hcf) << endl;
    return 0;
}