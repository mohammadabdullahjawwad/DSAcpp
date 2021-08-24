#include <bits/stdc++.h>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int lastIndex(int a[], int n, int key) {
    if(n == 0) {
        return -1;
    }
    if(a[n-1] == key) {
        return n - 1;
    }
    return lastIndex(a, n - 1, key);
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
    cout << lastIndex(a, n, key) << endl;
    return 0;
}