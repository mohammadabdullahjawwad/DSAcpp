#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int count = 0;

void subsequences(char* str, char* str1, int i, int j) {
    if(str[i] == '\0') {
        str1[j] = '\0';
        cout << str1 << " ";
        count++;
        return;
    }
    subsequences(str, str1, i + 1, j);
    str1[j] = str[i];
    subsequences(str, str1, i + 1, j + 1);
}

int main() {
    OJ;
    FIO;
    char str[1000];
    cin >> str;
    char str1[1000];
    subsequences(str, str1, 0, 0);
    cout << endl << count << endl;
    return 0;
}