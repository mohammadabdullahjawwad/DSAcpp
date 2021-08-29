#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void parenthesis(string arr, int o, int c, int i, int n) {
    if(i == 2 * n) {
        cout << arr << endl;
        return;
    }
    if(c < o) {
        parenthesis(arr + ')', o, c + 1, i + 1, n);
    }
    if(o < n) {
        parenthesis(arr + '(', o + 1, c, i + 1, n);
    }
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    string arr;
    parenthesis(arr, 0, 0, 0, n);
    return 0;
}