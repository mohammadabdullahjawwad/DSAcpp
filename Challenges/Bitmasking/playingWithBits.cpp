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
        int a, b;
        cin >> a >> b;
        int setBits = 0;
        for(int i=a; i<=b; i++) {
            setBits += __builtin_popcount(i);
        }
        cout << setBits << endl;
    }
	return 0;
}