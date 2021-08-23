#include<iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

bool palindrome(char* a, int s, int e) {
    if(s == e) {
        return true;
    }
    if(a[s] != a[e]) {
        return false;
    }
    if(s < e + 1) {
        return palindrome(a, s+1, e-1);
    }
    return true;
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    char* a = new char[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    if(palindrome(a, 0, n-1)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
	return 0;
}