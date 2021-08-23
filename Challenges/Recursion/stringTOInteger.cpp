#include <bits/stdc++.h>
using namespace std;

int ans = 0;

int stringToInt(char* str, int n) {
    if(n == 0) {
        return ans/10;
    }
    ans = ans + str[strlen(str)-n] - '0';
    ans *= 10;
    return stringToInt(str, n-1);
}

int main() {
    char str[100];
    cin >> str;
    int n = strlen(str);
    int num = stringToInt(str, n);
    cout << num << endl;
    return 0;
}