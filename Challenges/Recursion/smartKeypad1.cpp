#include <iostream>
using namespace std;

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

void keys(char* input, char* output, int i, int j) {
    if(input[i] == '\0') {
        output[j] = '\0';
        cout << output << endl;
        return;
    }
    int digit = input[i] - '0';
    for(int k=0; table[digit][k]!='\0'; k++) {
        output[j] = table[digit][k];
        keys(input, output, i+1, j+1);
    }
}

int main() {
    char input[100];
    char output[100];
    cin >> input;
    keys(input, output, 0, 0);
    return 0;
}