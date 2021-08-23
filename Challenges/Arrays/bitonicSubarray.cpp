#include<iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int bitonic(int a[], int n) {
	int inc[n]; // Length of increasing subarray ending at i
	int dec[n]; // Length of decreasing subarray ending at i
	inc[0] = 1;
	dec[n-1] = 1;
	for(int i=1; i<n; i++) {
		inc[i] = (a[i]>=a[i-1]) ? inc[i-1]+1 : 1;
	}
	for(int i=n-2; i>=0; i--) {
		dec[i] = (a[i]>=a[i+1]) ? dec[i+1]+1 : 1;
	}
	int length = inc[0] + dec[0] - 1;
	for(int i=1; i<n; i++) {
		length = max(length, inc[i] + dec[i] - 1);
	}
	return length;
}

int main() {
	OJ;
	FIO;
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		for(int i=0; i<n; i++) {
			cin >> a[i];
		}
		cout << bitonic(a, n) << endl;
	}
	return 0;
}