#include <iostream>
using namespace std;

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
    subsequences(input, output, i+1, j+1);
    // 2. Exclude the current character
    subsequences(input, output, i+1, j);
}

int main() {
    char input[100];
    cin >> input;
    char output[100];
    subsequences(input, output, 0, 0);
    cout << endl;
    return 0;
}
