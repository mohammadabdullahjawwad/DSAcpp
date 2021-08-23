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

int main() {
    OJ;
    FIO;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n];
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        int cs=0;
        int ms=0;
        for(int i=0; i<n; i++) {
            cs += a[i];
            if(cs < 0) {
                cs = 0;
            }
            ms = max(cs, ms);
        }
        cout << ms << endl;
    }
	return 0;
}