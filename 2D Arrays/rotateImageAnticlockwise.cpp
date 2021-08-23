#include<iostream>
#include<algorithm>
#include <vector>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void rotate(vector<vector<int>>& a, int n) {
	// Reverse each row
	for(int i=0; i<n; i++) {
		int sc = 0, ec = n - 1;
		while(sc < ec) {
			swap(a[i][sc], a[i][ec]);
			sc++, ec--;
		}
	}
	// Transpose the matrix
	for(int i=0; i<n; i++) {
		for(int j=0; j<i; j++) {
			swap(a[i][j], a[j][i]);
		}
	}
}

void rotateSTL(vector<vector<int>>& a, int n) {
	for(int i=0; i<n; i++) {
		reverse(a[i].begin(), a[i].end());
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<i; j++) {
			swap(a[i][j], a[j][i]);
		}
	}
}

void print(vector<vector<int>> a, int n) {
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	OJ;
	FIO;
	int n;
	cin >> n;
	vector<vector<int>> a;
	for(int i=0; i<n; i++) {
		vector<int> v;
		for(int j=0; j<n; j++) {
			int x;
			cin >> x;
			v.push_back(x);
		}
		a.push_back(v);
	}
	
	rotate(a, n);
	print(a, n);
	
	// rotateSTL(a, n);
	// print(a, n);
	
	return 0;
}