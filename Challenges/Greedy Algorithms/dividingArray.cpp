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
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        ll* a = new ll[n];
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        sort(a, a+n);
        int i = 0;
        int j = n - 1;
        ll maxans = 0;
        while(i < j) {
            maxans += abs(a[i] - a[j]);
            i++;
            j--;
        }
        ll minans = 0;
        i = 0;
        while(i < n-1) {
            minans += abs(a[i] - a[i+1]);
            i += 2;
        }
        cout << minans << " " << maxans << endl;
    }
    return 0;
}