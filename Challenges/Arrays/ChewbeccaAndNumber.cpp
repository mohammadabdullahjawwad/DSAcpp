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
	char num[50];
	cin >> num;
	int i=0;
	if(num[i] == '9') {
		i++;
	}
	for(; num[i]!='\0'; i++) {
		int digit = num[i] - '0';
		if(digit > 4) {
			digit = 9 - digit;
		}
		num[i] = digit + '0';
	}
	cout << num;
	return 0;
}