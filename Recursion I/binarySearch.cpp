#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int binarySearch(int a[], int s, int e, int key) {
    if(e < s) {
        return -1;
    }
    int mid = s + (e - s) / 2;
    if(key == a[mid]) {
        return mid;
    }
    if(key < a[mid]) {
        return binarySearch(a, s, mid - 1, key);
    }
    return binarySearch(a, mid + 1, e, key);
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
    cout << binarySearch(a, 0, n, key) << endl;
    return 0;
}