#include <bits/stdc++.h>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int convert(string str) {
    if(str.length() == 1) {
        return str[0] - '0';
    }
    int y = convert(str.substr(1));
    int x = str[0] - '0';
    x = x * pow(10, str.length() - 1) + y;
    return x;
}

int strToInt(char* a, int n) {
    if(!n) {
        return 0;
    } 
    int digit = a[n - 1] - '0';
    int smallAns = strToInt(a, n - 1);
    return smallAns * 10 + digit;
}

int main() {
    OJ;
    FIO;
    string str;
    cin >> str;
    cout << convert(str) << endl;
    // char a[10000];
    // cin >> a;
    // int n = strlen(a);
    // cout << strToInt(a, n) << endl;
    return 0;
}
