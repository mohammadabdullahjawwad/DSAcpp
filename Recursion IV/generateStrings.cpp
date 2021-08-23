#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void generateStrings(char* input, char* output, int i, int j) {
    if(input[i] == '\0') {
        output[j] = '\0';
        cout << output << endl;
        return;
    }
    // 1 digit at a time
    output[j] = input[i] - '0' + 'A' - 1;
    generateStrings(input, output, i + 1, j + 1);
    // 2 digits at a time
    if(input[i + 1] != '\0' && (input[i] - '0') * 10 + (input[i + 1] - '0') <= 26) {
        output[j] = ((input[i] - '0') * 10 + (input[i + 1] - '0')) + 'A' - 1;
        generateStrings(input, output, i + 2, j + 1);
    }
}

int main() {
    OJ;
    FIO;
    char* input = new char[1000];
    cin >> input;
    char* output = new char[1000];
    generateStrings(input, output, 0, 0);
    return 0;
}