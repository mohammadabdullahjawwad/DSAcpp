#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

char key[][10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void keypad(char* in, char* out, int i, int j) {
    if(in[i] == '\0') {
        out[j] = '\0';
        cout << out << endl;
        return;
    }
    int digit = in[i] - '0';
    if(digit == 0 || digit == 1) {
        keypad(in, out, i + 1, j);
    }
    for(int k=0; key[digit][k] != '\0'; k++) {
        out[j] = key[digit][k];
        keypad(in, out, i + 1, j + 1);
    }
}

int main() {
    OJ;
    FIO;
    char in[1000];
    cin >> in;
    char out[1000];
    keypad(in, out, 0, 0);
    return 0;
}