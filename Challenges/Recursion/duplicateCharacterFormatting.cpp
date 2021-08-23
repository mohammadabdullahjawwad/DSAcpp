#include <bits/stdc++.h>
using namespace std;

void format(char* str, int n) {
    if(n == 1) {
        cout << str[strlen(str)-1];
        return;
    }
    cout << str[strlen(str)-n];
    if(str[strlen(str)-n+1] == str[strlen(str)-n]) {
        cout << '*';
    }
    format(str, n-1);
}

int main() {
    char str[1000];
    cin >> str;
    int n = strlen(str);
    format(str, n);
    cout << endl;
    return 0;
}