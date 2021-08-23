#include <bits/stdc++.h>
using namespace std;

void replacePi(char str[], int start) {
    if(strlen(str) == start+1) {
        cout << str[start];
        return;
    }
    if(strlen(str) == start) {
        return;
    }
    if((str[start] == 'p') && (str[start+1] == 'i')) {
        cout << "3.14";
        replacePi(str, start+2);
    } else {
        cout << str[start];
        replacePi(str, start+1);
    }
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        char str[1000];
        cin >> str;
        replacePi(str, 0);
        cout << endl;
    }
    return 0;
}