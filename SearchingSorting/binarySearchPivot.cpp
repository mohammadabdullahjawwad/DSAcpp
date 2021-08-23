#include <iostream>
using namespace std;
int pivot(int *a, int s, int e) {
    if(s > e) {
        cout << "Pivot doesn't exist" << endl;
        return 0;
    }
    while (s <= e) {
        int m = (s+e)/2;
        if(a[m] < a[m-1]) {
            return m-1;
        }
        if(a[m] > a[m+1]) {
            return m;
        }
        if(a[e] <= a[m]) {
            pivot(a, m+1, e);
        } else if(a[s] >= a[m]) {
            pivot(a, s, m-1);
        }
    }
}
int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    cout << pivot(a, 0, n-1) << endl;
    return 0;
}