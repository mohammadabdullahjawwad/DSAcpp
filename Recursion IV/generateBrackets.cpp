#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void generateBrackets(int n, int open, int close, char *out) {
    if(open == n && close == n) {
        out[open + close] = '\0';
        cout << out << endl;
        return;
    }
    if(open < n) {
        out[open + close] = '(';
        generateBrackets(n, open + 1, close, out);
    }
    if(close < open) {
        out[open + close] = ')';
        generateBrackets(n, open, close + 1, out);
    }
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    char output[1000];
    generateBrackets(n, 0, 0, output);
    return 0;
}