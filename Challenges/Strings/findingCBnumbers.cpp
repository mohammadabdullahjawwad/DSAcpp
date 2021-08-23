#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <cmath>
#include <map>
#include <list>
#include <stack>
#include <queue>
using namespace std;

#define vll vector<ll>
#define pll pair<ll, ll>
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

// Understand this question thoroughly again

bool checkCB(long long num, int s, int e) {
    if(num == 0 || num == 1) {
        return false;
    }
    int arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    for(int i=0; i<sizeof(arr)/sizeof(int); i++) {
        if(num == arr[i]) {
            return true;
        }
    }
    for(int i=0; i<sizeof(arr)/sizeof(int); i++) {
        if(num % arr[i] == 0) {
            return false;
        }
    }
    return true;
}

bool isValid(bool visited[], int start, int end) {
    for(int i=start; i<end; i++) {
        if(visited[i]) {
            return false;
        }
    }
    return true;
}

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    bool visited[s.length()] = {false};
    int ans = 0;
    for(int len=1; len<=s.length(); len++) {
        for(int pos=0; pos<=s.length()-len; pos++) {
            int end = pos + len;
            string sub = s.substr(pos, len);
            if(checkCB(stoll(sub), pos, end) && isValid(visited, pos, end)) {
                ans++;
                for(int k=pos; k<end; k++) {
                    visited[k] = true;
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    OJ;
    FIO;
    // ll t;
    // cin >> t;
    // while(t--) {
        solve();
    // }
    return 0;
}