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

bool sortCheck(vector<int>& a, int n) {
	if(n == 0 || n == 1) {
		return true;
	}
	if(a[n - 1] < a[n - 2]) {
		return false;
	}
	return sortCheck(a, n - 1);
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
	string res;
	res = sortCheck(a, n) ? "true" : "false";
	cout << res << endl;
	return 0;
}