#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int main() {
	FIO;
	OJ;
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	// Taking Input
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> a[i][j];
		}
	}
	// Transposing the Matrix
	for(int i=0; i<n; i++) {
		for(int j=0; j<i; j++) {
			swap(a[i][j], a[j][i]);
		}
	}
	// Reversing Each Column
	for(int i=0; i<n/2; i++) {
		for(int j=0; j<n; j++) {
			swap(a[i][j], a[n-i-1][j]);
		}
	}
	// Printing the Result
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}