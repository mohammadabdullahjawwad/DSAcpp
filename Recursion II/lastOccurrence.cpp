#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int lastOcc(int a[], int n, int key) { // Arrays are always passed by reference in C++
    if(n == 0) {
        return -1;
    }
    int i = lastOcc(a + 1, n - 1, key);
    if(i == -1) {
        if(a[0] == key) {
            return 0;
        }
        return -1;
    }
    return i + 1;
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    int key;
    cin >> key;
    cout << lastOcc(a, n, key) << endl;
    return 0;
}