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

void clearBit(int& n, int i) {
    int mask = ~(1 << i);
    n = n & mask;
}

void updateBit(int& n, int i, int v) {
    int mask = ~(1 << i);
    int clearedN = n & mask; // these first two statements are used to clear the ith bit
    n = clearedN | (v << i);
}

int clearLastIBits(int n, int i) { // clears all bits from i+1th bit to 0th bit (counting of bits is done from right)
    int mask = (-1 << i);
    return n & mask;
}

int clearRangeIToJ(int n, int i, int j) {
    int a = (-1 << j + 1);
    int b = (1 << i) - 1;
    int mask = a | b;
    return n & mask;
}

int main() {
    OJ;
    FIO;
    int n, i;
    cin >> n >> i;
    // cout << isOdd(n) << endl;
    // cout << getBit(n, i) << endl;
    // cout << setBit(n, i) << endl;
    // clearBit(n, i);
    // cout << n << endl;
    // updateBit(n, 2, 0);
    // updateBit(n, 3, 1);
    // cout << n << endl;
    // cout << ~0 << endl; // this gives -1
    // cout << clearLastIBits(n, i) << endl;
    cout << clearRangeIToJ(n, 1, 3) << endl;
    return 0;
}