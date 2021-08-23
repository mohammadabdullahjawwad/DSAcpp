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
    char a;
    cin >> a;
    int num = a - '\0';
    if(num >= 65 && num <= 90) {
        cout << "UPPERCASE" << endl;
    }
    else if(num >= 97 && num <= 122) {
        cout << "lowercase" << endl;
    }
    else {
        cout << "Invalid" << endl;
    }
	return 0;
}