#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

// Method 1 - O(logN)
int countSetBits(int n) {
    int ans = 0;
    while(n > 0) {
        ans += n & 1;
        n = n >> 1;
    }
    return ans;
}

// Method 2 - O(no of set bits). In the worst case, no of set bits = logN, hence the worst case complexity is the same as first method
int countSetBitsFast(int n) {
    int ans = 0;
    while(n > 0) { //  no of times while loop is executing is the ans
        n = n & (n-1); // removes the last set bit
        ans++;
    }
    return ans;
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    cout << countSetBits(n) << endl;
    cout << countSetBitsFast(n) << endl;
    cout << __builtin_popcount(n) << endl; // Method 3 (Built-in function)
    return 0;
}