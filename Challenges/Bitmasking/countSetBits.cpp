#include<iostream>
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
        cout << __builtin_popcount(n) << endl;
    }
	return 0;
}