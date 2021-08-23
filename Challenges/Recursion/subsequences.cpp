#include <iostream>
using namespace std;

int count = 0;

void subsequences(char* str, char* str1, int i, int j) {
    if(str[i] == '\0') {
        str1[j] = '\0';
        cout << str1 << " ";
        count++;
        return;
    }
    subsequences(str, str1, i+1, j);
    str1[j] = str[i];
    subsequences(str, str1, i+1, j+1);
}

int main() {
    char str[1000];
    cin >> str;
    char str1[1000];
    subsequences(str, str1, 0, 0);
    cout << endl << count << endl;
    return 0;
}