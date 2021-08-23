#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

bool myCompare(string x, string y) {
    string xy = x.append(y);
    string yx = y.append(x);
    return (xy.compare(yx) > 0) ? true : false;
}

void formBiggestNumber(string a[], int n) {
    sort(a, a+n, myCompare);
    for(int i=0; i<n; i++) {
        cout << a[i];
    }
    cout << endl;
}

int main() {
    OJ;
    FIO;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string a[n];
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        formBiggestNumber(a, n);
    }
	return 0;
}