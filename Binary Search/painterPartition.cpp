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

bool check(ll n, ll k, vll& board, ll m) {
    ll painter = 1;
    ll done = 0;
    for(int i = 0; i<n; i++) {
        if(done + board[i] > m) {
            painter++;
            done = board[i];
            if(painter > k) {
                return false;
            }
        }
        else {
            done += board[i];
        }
    }
    return true;
}

ll binarySearch(ll n, ll k, vll& board) {
    ll s = board[n-1];
    ll e = 0;
    for(ll i = 0; i<n; i++) {
        e += board[i];
    }
    ll ans = s;
    ll m = s + (e - s) / 2;
    if(check(n, k, board, m)) {
        ans = m;
        e = m - 1;
    }
    else {
        s = m + 1;
    }
    return ans;
}

void solve() {
    ll k, n;
    cin >> k >> n;
    vector<ll> board(n);
    for(ll i = 0; i < n; i++) {
        cin >> board[i];
    }
    sort(board.begin(), board.end());
    cout << binarySearch(k ,n, board) << endl;
}

// This solution gives incorrect answer in hackerblocks : https://hack.codingblocks.com/app/practice/1/1057/problem
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