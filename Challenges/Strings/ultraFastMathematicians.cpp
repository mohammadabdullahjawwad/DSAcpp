#include <iostream>
#include <cstring>
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
        char a[100], b[100];
        cin >> a >> b;
        int i = 0;
        while(i < strlen(a)) {
            cout << (a[i] != b[i]);
            i++;
        }
        cout << endl;
    }
	return 0;
}