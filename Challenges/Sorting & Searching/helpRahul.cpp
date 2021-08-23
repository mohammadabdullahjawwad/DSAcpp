#include<iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int search(int a[], int s, int e, int key) {
    if(s > e) {
        return -1;
    }
    int m = s + (e - s) / 2;
    if(a[m] == key) {
        return m;
    }
    if(a[s] <= a[m]) {
        if(key >= a[s] && key <= a[m]) {
            return search(a, s, m - 1, key);
        }
        return search(a, m + 1, e, key);
    }
    if(key >= a[m] && key <= a[e]) {
        return search(a, m + 1, e, key);
    }
    return search(a, s, m - 1, key);
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
    cout << search(a, 0, n - 1, key) << endl;
	return 0;
}