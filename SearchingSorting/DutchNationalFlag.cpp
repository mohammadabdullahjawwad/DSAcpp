#include<bits/stdc++.h>
using namespace std;
void DutchSort(int *a, int n) {
    int lo = 0;
    int mid = 0;
    int hi = n-1;
    while(mid <= hi) {
        if(a[mid] == 1) {
            mid++;
        } else if(a[mid] == 2) {
            swap(a[mid], a[hi]);
            hi--;
        } else {
            swap(a[mid], a[lo]);
            lo++;
            mid++;
        }
    }
}
int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    DutchSort(a, n);
    for (int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}