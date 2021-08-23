#include <iostream>
#include <algorithm>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

bool compare(pair<string, int> p1, pair<string, int> p2) {
    if(p1.second == p2.second) {
        return p1.first < p2.first; 
    }
    return p1.second > p2.second;
}

int main() {
	OJ;
	FIO;
    int x;
    cin >> x;
	int n;
	cin >> n;
	pair<string, int> emp[100000];
	string name;
	int salary;
	for(int i=0; i<n; i++) {
	    cin >> name >> salary;
	    emp[i].first = name;
	    emp[i].second = salary;
	}
	sort(emp, emp + n, compare);
	for(int i=0; i<n; i++) {
	    if(emp[i].second >= x) {
	        cout << emp[i].first << " " << emp[i].second << endl;
	    }
	}
	return 0;
}