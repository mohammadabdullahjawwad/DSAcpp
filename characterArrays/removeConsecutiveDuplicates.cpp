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

void removeDuplicates(char* a) {
    if(!strlen(a) || strlen(a) == 1) {
        return;
    }
    int j = 0;
    for(int i=1; i<strlen(a); i++) {
        if(a[i] != a[j]) {
            j++;
            a[j] = a[i];
        }
    }
    a[j+1] = '\0';
}

int main() {
    OJ;
    FIO;
    char a[1000];
    cin.getline(a, 1000);
    removeDuplicates(a);
    cout << a << endl;
    return 0;
}