#include <iostream>
#include<algorithm>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void countSort1(int *a, int n, int k) {
    int f[k+1] = {0};
    for(int i=0; i<n; i++) {
        f[a[i]]++;
    }
    for(int i=1; i<=k; i++) {
        f[i] += f[i-1];
    }
    int* b = new int[n];
    for(int i=n-1; i>=0; i--) {
        b[--f[a[i]]] = a[i];
    }
    for(int i=0; i<n; i++) {
        a[i] = b[i];
    }
}

void countSort2(int* a, int n, int k) {
    int f[k+1] = {0};
    for(int i=0; i<n; i++) {
        f[a[i]]++;
    }
    int count = 0;
    for(int i=0; i<=k; i++) {
        while(f[i]--) {
            a[count++] = i;
        }
    }
}

int main() {
    OJ;
    FIO;
	int n;
	cin >> n;
	int a[n];
    int k = 0;
	for(int i=0; i<n; i++) {
	    cin >> a[i];
        k = max(k, a[i]);
	}
    // countSort1(a, n, k);
    countSort2(a, n, k);
    for(int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
	return 0;
}