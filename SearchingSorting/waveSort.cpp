#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++) {
	    cin >> a[i];
	}
    // 	Insertion Sort
    for(int i=0; i<n; i+=2) {
        if(i>0 && a[i-1]>a[i]) {
            swap(a[i-1], a[i]);
        }
        if(i<n-1 && a[i]<a[i+1]) {
            swap(a[i], a[i+1]);
        }
    }
    for(int i=0; i<n; i++) {
        cout << a[i] << endl;
    }
	return 0;
}