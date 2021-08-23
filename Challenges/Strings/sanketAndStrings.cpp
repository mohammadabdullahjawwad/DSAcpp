#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<cstring>
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
	int k;
	cin >> k;
	// cout << k << endl;
	string str;
	cin >> str;
	// cout << str << endl;
	if(k >= str.length()) {
		cout << str.length() << endl;
		return 0;
	}
	int ans = 0;
	int count[] = {0, 0}; // Stores the frequencies of a and b respectively
	int left = 0;
	for(int right=0; right<str.length(); right++) {
		count[str[right] - 'a']++;
		if(min(count[0], count[1]) > k) {
			count[str[left] - 'a']--;
			left++;
		}
		else {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}