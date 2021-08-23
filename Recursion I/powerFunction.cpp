#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

// Approach 1 (brute force) starts here
int power1(int a, int b) {
    if(b == 0) {
        return 1;
    }
    return a * power1(a, b - 1);
}
// Approach 1 ends here

// Approach 2 (Optimisation) starts here
int power2(int a, int b) {
    if(b == 0) {
        return 1;
    }
    if(b & 1) {
        return a * power2(a, b / 2) * power2(a, b / 2);
    }
    return power2(a, b / 2) * power2(a, b / 2);
}
// Approach 2 ends here

int main() {
    OJ;
    FIO;
    int a, b;
    cin >> a >> b;
    cout << power1(a, b) << endl;
    cout << power2(a, b) << endl;
    return 0;
}