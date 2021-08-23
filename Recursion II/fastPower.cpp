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
int power(int a, int b) {
    if(b == 0) {
        return 1;
    }
    return a * power(a, b - 1);
}
// Approach 1 ends here

// Approach 2 (Optimisation) starts here
int fastPower(int a, int b) {
    if(b == 0) {
        return 1;
    }
    int smallerAns = fastPower(a, b / 2);
    smallerAns *= smallerAns; // Don't call the function recursively twice(inefficient approach). Instead, multiply the result after recursion with itself
    if(b & 1) {
        return a * smallerAns;
    }
    return smallerAns;
}
// Approach 2 ends here

int main() {
    OJ;
    FIO;
    int a, b;
    cin >> a >> b;
    cout << power(a, b) << endl;
    cout << fastPower(a, b) << endl;
    return 0;
}