#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void readline(char a[], int maxLen, char delim = '\n') {
    int i = 0;
    char ch = cin.get(); // this function reads a full sentence unlike cin >>
    while(ch != delim) {
        a[i] = ch;
        i++;
        if(i == maxLen - 1) {
            break;
        }
        ch = cin.get();
    }
    a[i] = '\0';
    return;
}

int main() {
    OJ;
    FIO;
    char a[1000];
    // readline(a, 1000, '$');
    cin.getline(a, 1000, '$'); // STL function for readline()
    cout << a << endl;
    return 0;
}