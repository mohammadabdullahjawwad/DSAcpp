#include <bits/stdc++.h>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void replacePi(char str[], int start) {
    if(strlen(str) == start + 1) {
        cout << str[start];
        return;
    }
    if(strlen(str) == start) {
        return;
    }
    if(str[start] == 'p' && str[start+1] == 'i') {
        cout << "3.14";
        replacePi(str, start + 2);
    }
    else {
        cout << str[start];
        replacePi(str, start + 1);
    }
}

int main() {
    OJ;
    FIO;
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