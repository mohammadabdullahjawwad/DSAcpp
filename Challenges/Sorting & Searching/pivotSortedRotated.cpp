#include <iostream>
#include <vector>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int pivot(vector<int>& a, int n, int s, int e) {
    if(s > e) {
        return -1;
    }
    int m = s + (e - s) / 2;
    if(a[s] <= a[m] && a[m] >= a[e]) {
        return m;
    }
    if(a[s] <= a[m]) {
        return pivot(a, n, m + 1, e);
    }
    return pivot(a, n, s, m - 1);
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    cout << pivot(a, n, 0, n - 1) << endl;
    return 0;
}