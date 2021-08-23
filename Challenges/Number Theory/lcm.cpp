#include <iostream>
using namespace std;

#define ll long long int

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

ll gcd(ll a, ll b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    OJ;
    FIO;
    ll a, b;
    cin >> a >> b;
    ll hcf = gcd(a, b);
    cout << a * b / hcf << endl;
    return 0;
}