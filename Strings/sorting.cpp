#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>
#include <map>
#include <list>
#include <queue>
using namespace std;

#define vi vector<int>
#define pii pair<int ,int>
#define all(v) v.begin(), v.end()
#define pub push_back
#define pob pop_back
#define mp make_pair
#define ll long long int
#define MOD 1000000007
#define clr(val) memset(val,0,sizeof(val))

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

bool compare(string a, string b) {
    if(a.length() == b.length()) {
        return a < b;
    }
    return a.length() > b.length();
}

int main() {
    OJ;
    FIO;
    
    int n;
    cin >> n;
    cin.get();
    string s[100];

    for(int i=0; i<n; i++) {
        getline(cin, s[i]);
    }

    sort(s, s+n, compare);

    for(int i=0; i<n; i++) {
        cout << s[i] << endl;
    }

    return 0;
}