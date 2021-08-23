#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int lower(int* a, int s, int e, int ans, int key) {
    while(s <= e) {
        int m = s + (e - s) / 2;
        if(key == a[m]) {
            ans = m;
            e = m - 1;
        }
        else if(key > a[m]) {
            s = m + 1;
        }
        else {
            e = m - 1;
        }
    }
    return ans;
}
int upper(int* a, int s, int e, int ans, int key) {
    while(s <= e) {
        int m = s + (e - s) / 2;
        if(key == a[m]) {
            ans = m;
            s = m + 1;
        }
        else if(key > a[m]) {
            s = m + 1;
        }
        else {
            e = m - 1;
        }
    }
    return ans;
}
void binarySearch(int *a, int n, int key) {
    int s = 0;
    int e = n - 1;
    int ans = -1;
    cout << lower(a, s, e, ans, key) << " " << upper(a, s, e, ans, key) << endl;
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
    int t;
    cin >> t;
    while(t--) {
        int key;
        cin >> key;
        binarySearch(a, n, key);
    }
    return 0;
}