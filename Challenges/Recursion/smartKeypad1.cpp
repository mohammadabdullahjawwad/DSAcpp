#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

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
    OJ;
    FIO;
    char input[100];
    cin >> input;
    char output[100];
    keys(input, output, 0, 0);
    return 0;
}