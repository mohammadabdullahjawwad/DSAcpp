#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int binarySearch(int *a, int n, int key) {
    int s = 0;
    int e = n - 1;
    while(s <= e) {
        int m = s + (e - s) / 2;
        if(key == a[m]) {
            return m;
        }
        if(key > a[m]) {
            s = m + 1;
        } 
        else {
            e = m - 1;
        }
    }
    return -1;
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
    int index = binarySearch(a, n, key);
    if(index == -1) {
        cout << key << " is not present" << endl;
    }
    else{
        cout << key << " is present at index " << index << endl;
    }
    return 0;
}