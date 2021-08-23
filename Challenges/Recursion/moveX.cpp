#include <iostream>
#include <cstring>
using namespace std;

void moveX(char* str, char* out, char* x, int i, int j, int k) {
    if(str[i] == '\0') {
        cout << out << x << endl;
        return;
    }
    if(str[i] == 'x') {
        x[k] = str[i];
        moveX(str, out, x, i+1, j, k+1);
    } else {
        out[j] = str[i];
        moveX(str, out, x, i+1, j+1, k);
    }
}

int main() {
    char str[1000];
    cin >> str;
    char out[900] = "";
    char x[100] = "";
    moveX(str, out, x, 0, 0, 0);
    return 0;
}