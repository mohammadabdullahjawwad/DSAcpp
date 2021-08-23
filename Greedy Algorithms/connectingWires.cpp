#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
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

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    vi white;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        white.pub(x);
    }
    sort(white.begin(), white.end());
    vi black;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        black.pub(x);
    }
    sort(black.begin(), black.end());
    int ans = 0;
    for(int i=0; i<n; i++) {
        ans += abs(black[i] - white[i]);
    }
    cout << ans << endl;
    return 0;
}