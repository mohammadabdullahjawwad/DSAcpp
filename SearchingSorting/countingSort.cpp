#include <iostream>
#include<algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[n];
    int k=0;
	for(int i=0; i<n; i++) {
	    cin >> a[i];
        k = max(k, a[i]);
	}
    int f[k+1] = {0};
    for(int i=0; i<n; i++) {
        f[a[i]]++;
    }
    int count = 0;
    for(int i=0; i<=k; i++) {
        while(f[i] > 0) {
            a[count] = i;
            f[i]--;
            count++;
        }
    }
    for(int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
	return 0;
}