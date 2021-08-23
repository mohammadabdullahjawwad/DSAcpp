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
    int n, d;
    cin >> n >> d;
    int *l = new int[n];
    for(int i=0; i<n; i++) {
        cin >> l[i];
    }
    sort(l, l+n);
    int pairs = 0;
    int i = 0;
    while(i < n-1) {
        if(l[i+1] - l[i] <= d) {
            pairs += 1;
            i += 2;
        }
        else {
            i++;
        }
    }
    cout << pairs << endl;
    return 0;
}