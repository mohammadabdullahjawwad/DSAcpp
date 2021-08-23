#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

bool isValidConfig(int* a, int n, int m, int c) {
    int cow = 1;
    int pos = a[0];
    for(int i=1; i<n; i++) {
        if(a[i] - pos >= m) {
            pos = a[i];
            cow++;
            if(cow == c) {
                return 1;
            }
        }
    }
    return 0;
}

int binarySearch(int* a, int n, int c) {
    int s = a[0];
    int e = a[n-1] - a[0];
    int mx = 0;
    while(s <= e) {
        int m = s + (e - s) / 2;
        if(isValidConfig(a, n, m, c)) {
            mx = max(mx, m);
            s = m + 1;
        }
        else {
            e = m - 1;
        }
    }
    return mx;
}

int main() {
    OJ;
    FIO;
    int n, c;
    cin >> n >> c;
    int a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    cout << binarySearch(a, n, c) << endl;
	return 0;
}