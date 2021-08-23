#include <iostream>
#include <vector>
#include <string.h>
#include <unordered_set>
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

int distinctSubarrayLength(int *a, int n) {
    unordered_set<int> m;
    int ans = 0;
    int j = 0;
    for(int i=0; i<n; i++) {
        while(j<n && m.find(a[j]) == m.end()) {
            m.insert(a[j]);
            j++;
        }
        ans += ((j-i)*(j-i+1))/2;
        m.erase(a[i]);
    }
    return ans;
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    int* a = new int[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    cout << distinctSubarrayLength(a, n) << endl;;
    return 0;
}