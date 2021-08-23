#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int linearSearch1(int a[],int i, int n, int key) {
    if(i == n) {
        return -1;
    }
    if(a[i] == key) {
        return i;
    }
    return linearSearch1(a, i + 1, n, key);
}

int linearSearch2(int a[], int n, int key) {
    if(n == 0) {
        return -1;
    }
    if(a[0] == key) {
        return 0;
    }
    int i = linearSearch2(a + 1, n - 1, key);
    if(i == -1) {
        return -1;
    }
    return i + 1;
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    int *a = new int[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    int key;
    cin >> key;
    cout << linearSearch1(a, 0, n, key) << endl;
    cout << linearSearch2(a, n, key) << endl;
    return 0;
}