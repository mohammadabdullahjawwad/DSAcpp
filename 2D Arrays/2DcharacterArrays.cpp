#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int main() {
    OJ;
    FIO;

    char a[][10] = {{'a', 'b', '\0'}, {'d', 'e', 'f', '\0'}};
    cout << a[0] << endl;
    cout << a[1] << endl << endl;

    char b[][10] = {"ab", "def", "ghi", "hello"};
    cout << b[0] << endl;
    cout << b[1] << endl;
    cout << b[2] << endl;
    cout << b[3] << endl;

    char c[10][10];
    c[0][0] = 'A';
    
    return 0;
}