#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void subsequences(char *input, char *output, int i, int j) {
    // Base Case
    if(input[i] == '\0') {
        output[j] = '\0';
        cout << "\"" << output << "\" ";
        return;
    }
    // Recursive Case(s) - 2 options for each character
    // 1. Include the current character
    output[j] = input[i];
    subsequences(input, output, i + 1, j + 1);
    // 2. Exclude the current character
    subsequences(input, output, i + 1, j);
}

// Point to be noted : In recursion, arrays are passed by reference
int main() {
    OJ;
    FIO;
    char input[100];
    cin >> input;
    char output[100];
    subsequences(input, output, 0, 0);
    cout << endl;
    return 0;
}
