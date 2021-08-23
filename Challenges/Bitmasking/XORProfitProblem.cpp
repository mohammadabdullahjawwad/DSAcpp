#include<iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int main () {
    OJ;
    FIO;
    int x, y;
    cin >> x >> y;
    int max_xor = 0;
    int exor;
    for(int i=x; i<=y; i++) {
        for(int j=i; j<=y; j++) {
            exor = i^j;
            max_xor = max(max_xor, exor);
        }
    }
    cout << max_xor << endl;
	return 0;
}