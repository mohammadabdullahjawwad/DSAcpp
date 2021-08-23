#include<iostream>
#include<algorithm>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void arraySum(int a[1000], int n, int b[1000], int m) {
    int ans[1000];
    int carry = 0, sum = 0;
    int i = n, j = m;
    while(i >= 0 && j >= 0) { // Common indexes
        int k = max(i, j) + 1;
        ans[k] = a[i] + b[j] + carry;
        carry = ans[k] / 10;
        ans[k] %= 10;
        i--;
        j--;
    }
    for(int k = max(m,n) - min(m, n); k>0; k--) { // Remaining indices of larger array
        ans[k] = (n > m ? a[k-1] : b[k-1]) + carry;
        carry = ans[k] / 10;
        ans[k] %= 10;
    }
    ans[0] = carry;
    if(ans[0] > 0) {
        cout << ans[0] << ", ";
    }
    for(int i=1; i<=max(m, n); i++) {
        cout << ans[i] << ", ";
    }
    cout << "END" << endl;
}

int main() {
    FIO;
    OJ;
    int n;
    cin >> n;
    int a[1000];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    int b[1000];
    for(int i=0; i<m; i++) {
        cin >> b[i];
    }
    arraySum(a, n, b, m);
	return 0;
}