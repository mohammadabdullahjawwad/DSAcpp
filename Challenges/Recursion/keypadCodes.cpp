#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

string table[] = {"", "abc", "def", "ghi", "jkl" , "mno", "pqrs", "tuv", "wx", "yz"};
int count = 0;

void keys(char* input, char* output, int i, int j) {
    if(input[i] == '\0') {
        output[j] = '\0';
        count++;
        cout << output << " ";
        return;
    }
    int digit = input[i] - '0';
    for(int k=0; table[digit][k]!='\0'; k++) {
        output[j] = table[digit][k];
        keys(input, output, i + 1, j + 1);
    }
}

int main() {
    OJ;
    FIO;
    char input[100];
    char output[100];
    cin >> input;
    keys(input, output, 0, 0);
    cout << endl << count << endl;
    return 0;
}