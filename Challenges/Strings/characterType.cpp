#include<iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

char check(int num) {
	if(num >=65 && num <= 90) {
		return 'U';
	} else if(num >=97 && num <= 122) {
		return 'L';
	} else {
		return 'I';
	}
}

int main() {
	OJ;
	FIO;
	char ch;
	cin >> ch;
	int num = ch - '\0';
	cout << check(num) << endl;
	return 0;
}