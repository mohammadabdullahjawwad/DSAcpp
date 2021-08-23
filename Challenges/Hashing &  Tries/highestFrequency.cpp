#include <iostream>
#include <vector>
#include <string.h>
#include <map>
using namespace std;

#define vi vector<int>
#define pii pair<int ,int>
#define all(v) v.begin(), v.end()
#define mp make_pair
#define ll long long int
#define MOD 1000000007
#define clr(val) memset(val,0,sizeof(val))

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO \
       ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

int maxFreq(int *a, int n) {
    unordered_map<int, int> m;
    int ans = 0;
    int freq = 0;
    for(int i = 0; i < n; i++) {
        m[a[i]]++;
    }
    for(int i = 0; i < n; i++) {
        if(freq < m[a[i]]) {
            freq = m[a[i]];
            ans = a[i];
        }
    }
    return ans;
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    cout << maxFreq(a, n) << endl;
    return 0;
}

// The complexity of unordered_map is less than that of map