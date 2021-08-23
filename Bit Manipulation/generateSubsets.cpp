#include <iostream>
#include <string>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void filter(string a, int n) {
    int j = 0;
    while(n > 0) {
        int lbit = (n & 1);
        if(lbit) {
            cout << a[j];
        }
        j++;
        n >>= 1;
    }
    cout << endl;
}

void printSubsets(string a) {
    int n = a.length();
    for(int i=0; i<(1<<n); i++) {
        filter(a, i);
    }
}

int main() {
    OJ;
    FIO;
    string a;
    cin >> a;
    printSubsets(a);
    return 0;
}
