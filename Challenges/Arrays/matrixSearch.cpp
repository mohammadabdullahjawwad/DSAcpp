#include<iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

bool stairCaseSearch(int a[][30], int n, int m, int key) {
	int i = 0, j = m - 1;
	while((j > 0) && (i < n)) {
		if(a[i][j] == key) {
			return true;
		}
		if(a[i][j] < key) {
			i++;
		}
		else {
			j--;
		}
	}
	return false;
}

int main() {
	OJ;
	FIO;
	int n, m;
	cin >> n >> m;
	int a[30][30];
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> a[i][j];
		}
	}
	int key;
	cin >> key;
	cout << stairCaseSearch(a, n, m, key) << endl;
	return 0;
}