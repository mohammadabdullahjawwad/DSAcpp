#include<iostream>
#include <algorithm>
#include <climits>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int maxVal(int *a, int N) {
	int ans = INT_MIN;
	for(int i=0; i<N; i++) {
		ans = max(ans, a[i]);
	}
	return ans;
}

int main() {
	OJ;
	FIO;
	int N;
	cin >> N;
	int a[N];
	for(int i=0; i<N; i++) {
		cin >> a[i];
	}
	cout << maxVal(a,N) << endl;
	return 0;
}