#include<iostream>
using namespace std;

bool sortCheck(int *a, int n) {
	if((n == 0) || (n == 1)) {
		return true;
	}
	if(a[n-1] < a[n-2]) {
		return false;
	}
	return sortCheck(a, n-1);
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	if(sortCheck(a, n)) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}
	return 0;
}