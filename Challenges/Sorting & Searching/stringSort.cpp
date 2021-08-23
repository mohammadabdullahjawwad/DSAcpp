#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

bool compare(string a, string b) {
    if((a.find(b) == 0) || (b.find(a) == 0)) {
        return a.length() > b.length();
    }
    return a < b;
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    string s[n];
    for(int i=0; i<n; i++) {
        cin >> s[i];
    }
    sort(s, s+n, compare);
    for(int i=0; i<n; i++) {
        cout << s[i] << endl;
    }
	return 0;
}