#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void inc(int n) {
    if(n <= 0) {
        return;
    }
    inc(n - 1);
    cout << n << " "; // Since it is written after the recursive function call, this makes it bottom up recursive approach
}

void dec(int n) {
    if(n <= 0) {
        return;
    }
    cout << n << " "; // Since it is written before the recursive function call, this makes it top down recursive approach
    dec(n - 1);
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    inc(n);
    cout << endl;
    dec(n);
    cout << endl;
    return 0;
}