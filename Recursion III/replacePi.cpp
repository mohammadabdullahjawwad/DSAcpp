#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void replacePi(char a[], int i) {
    if(a[i] == '\0' || a[i + 1] == '\0') {
        return;
    }
    if(a[i] == 'p' && a[i + 1] == 'i') {
        int j = i + 2; // Since pi has 2 characters
        while(a[j] != '\0') { // Take j to the end of the array
            j++;
        }
        // Shifting right to left all characters ahead to accommodate 3.14 which has 4 characters in place of pi which has 2 characters
        while(j >= i + 2) {
            a[j + 2] = a[j];
            j--;
        }
        // Replacement + recursive call
        a[i] = '3'; 
        a[i + 1] = '.'; 
        a[i + 2] = '1'; 
        a[i + 3] = '4'; 
        replacePi(a, i + 4);
    }
    else {
        replacePi(a, i + 1);
    }
}

int main() {
    OJ;
    FIO;
    char a[100000];
    cin >> a;
    replacePi(a, 0);
    cout << a << endl;
    return 0;
}