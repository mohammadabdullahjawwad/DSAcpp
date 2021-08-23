#include<bits/stdc++.h>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);


void DutchSort(int *a, int n) {
    int lo = 0;
    int mid = 0;
    int hi = n - 1;
    while(mid <= hi) {
        if(a[mid] == 1) {
            mid++;
        }
        else if(a[mid] == 2) {
            swap(a[mid], a[hi]);
            hi--;
        }
        else {
            swap(a[mid], a[lo]);
            lo++;
            mid++;
        }
    }
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    DutchSort(a, n);
    for (int i=0; i<n; i++) {
        cout << a[i] << endl;
    }
    return 0;
}