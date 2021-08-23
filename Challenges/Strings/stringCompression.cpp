#include <iostream>
#include <string>
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
    string a;
    cin >> a;
    cout << a[0];
    int count = 1;
    for(int i=1; i<a.length(); i++) {
        if(a[i] == a[i-1]) {
            count++;
        }
        else {
            cout << count << a[i];
            count = 1;
        }
    }
    cout << count << endl;
	return 0;
}