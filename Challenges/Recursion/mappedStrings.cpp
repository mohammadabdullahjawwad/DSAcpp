#include <iostream>
using namespace std;

void hashmap(char in[],int i, int j, char out[]) {
    if(in[i] == '\0') {
        out[j] = '\0';
        cout << out << endl;
        return;
    }
    // Include single character
    int digit = in[i] - '0';
    char ch = digit + 'A' - 1;
    out[j] = ch;
    hashmap(in, i+1, j+1, out);
    // Include two characters
    if(in[i+1] != '\0') {
        int secondDigit = in[i+1] - '0';
        int no = 10*digit + secondDigit;
        if(no <= 26) {
            ch = no + 'A' - 1;
            out[j] = ch;
            hashmap(in, i+2, j+1, out);
        }
    }
}

int main() {
    char in[10];
    cin >> in;
    char out[10];
    hashmap(in, 0, 0, out);
    return 0;
}