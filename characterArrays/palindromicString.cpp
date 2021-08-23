#include <iostream>
#include <string.h>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

bool isPalindrome(char a[]) {
    int i = 0;
    int j = strlen(a) - 1;
    while(i < j) {
        if(a[i] != a[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    OJ;
    FIO;
    char a[1000];
    cin.getline(a, 1000);
    cout << isPalindrome(a) << endl;
    return 0;
}