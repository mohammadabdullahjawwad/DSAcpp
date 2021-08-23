#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void multiply(int i, int result[], int& len) {
    int carry = 0;
    for(int j=0; j<len; j++) {
        int ans = result[j] * i + carry;
        result[j] = ans % 10;
        carry = ans / 10;
    }
    while(carry) {
        result[len] = carry % 10;
        carry /= 10;
        len++;
    }
}

void factorial(int n) {
    int result[1135]; // 500! has 1135 digits (OMG, right?).Using INT_MAX here instead of 1135 gives segmentation fault :'(
    result[0] = 1;
    int len = 1;
    for(int i=2; i<=n; i++) {
        multiply(i, result, len);
    }
    for(int i=len-1; i>=0; i--) {
        cout << result[i];
    }
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
	if((n == 0) || (n == 1)) {
		cout << 1;
	}
    else {
    	factorial(n);
	}
    cout << endl;
    return 0;
}