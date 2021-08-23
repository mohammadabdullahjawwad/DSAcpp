#include <iostream>
#include <vector>
#include <unordered_map>
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

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int rightTriangle(vi a, vi b) {
    int ans = 0;
    unordered_map<int, int> x, y;
    for(int i : a) {
        x[i]++;
    }
    for(int i : b) {
        y[i]++;
    }
    for(int i=0; i<a.size(); i++) {
        ans = (ans + (x[a[i]] - 1) * (y[b[i]] - 1)) % MOD;
    }
    return ans;
}

int main() {
    OJ;
    int n;
    cin >> n;
    vi a, b;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        a.pub(x);
    }
    for(int i=0; i<n; i++) {
        int y;
        cin >> y;
        b.pub(y);
    }
    int count = rightTriangle(a, b);
    cout << count << endl;
    return 0;
}

// Not understanding the errors - Error removed - was not using iterators correctly. Also there was a syntax error in inserting the pairs in map.

// Update - showing run time error in interviewbit - because of constraints. Use the update code