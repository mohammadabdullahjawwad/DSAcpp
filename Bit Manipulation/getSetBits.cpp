#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

bool isOdd(int n) {
    return n & 1;
}

int getBit(int n, int i) { // returns ith bit from right. i starts from 0 not 1
    int mask = (1 << i);
    int bit = ((n & mask) > 0) ? 1 : 0;
    return bit;
}

int setBit(int& n, int i) { // sets ith bit from right. i starts from 0
    int mask = (1 << i);
    int ans = n | mask;
    return ans;
}

int main() {
    OJ;
    FIO;
    int n, i;
    cin >> n >> i;
    cout << isOdd(n) << endl;
    cout << getBit(n, i) << endl;
    cout << setBit(n, i) << endl;
    return 0;
}