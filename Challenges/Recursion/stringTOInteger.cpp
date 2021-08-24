#include <bits/stdc++.h>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int ans = 0;

int stringToInt(string str, int n, int i) {
    if(i == n) {
        return ans / 10;
    }
    ans += str[i] - '0';
    ans *= 10;
    return stringToInt(str, n, i + 1);
}

int stringToInt(char* str, int n) {
    if(n == 0) {
        return ans / 10;
    }
    ans += str[strlen(str) - n] - '0';
    ans *= 10;
    return stringToInt(str, n - 1);
}

int main() {
    OJ;
    FIO;
    // string str;
    char str[100];
    cin >> str;
    // int n = str.length();
    int n = strlen(str);
    // int num = stringToInt(str, n, 0);
    int num = stringToInt(str, n);
    cout << num << endl;
    return 0;
}