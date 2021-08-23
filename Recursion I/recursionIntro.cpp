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

ll factorial(ll n) {
    // Base Case
    if(n == 0) {
        return 1;
    }
    // Recursive case
    return n * factorial(n - 1);
}

int main() {
    OJ;
    FIO;
    ll n;
    cin >> n;
    cout << factorial(n) << endl;
    return 0;
}