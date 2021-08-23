#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

bool compare(int a, int b) {
    return a < b;
}

int main() {
    OJ;
    FIO;
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++) {
        cin >> a[i];
	}
    sort(a.begin(), a.end(), compare); // passing compare (function name) as a parameter to sort() function
    for(int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
	return 0;
}

// int main() {
//     OJ;
//     FIO;
// 	int n;
// 	cin >> n;
// 	int* a = new int[n];
// 	for(int i=0; i<n; i++) {
//         cin >> a[i];
// 	}
//     sort(a, a+n, compare);
//     for(int i=0; i<n; i++) {
//         cout << a[i] << " ";
//     }
//     cout << endl;
// 	return 0;
// }