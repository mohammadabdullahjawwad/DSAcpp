#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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

int submatrixSum(vector<vector<int>> a, int tli, int tlj, int bri, int brj) {
    int sum = a[bri][brj];
    if(tli > 0) {
        sum -= a[tli-1][brj];
    }
    if(tlj > 0) {
        sum -= a[bri][tlj-1];
    }
    if(tli > 0 && tlj > 0) {
        sum += a[tli-1][tlj-1];
    }
    return sum;
}

int main() {
    OJ;
    FIO;
    int r, c;
    cin >> r >> c;
    vector<vector<int>> a(r, vector<int>(c));
    for(int i=0; i<r; i++) {
        vector<int> v;
        for(int j=0; j<c; j++) {
            cin >> a[i][j];
        }
    }
    for(int i=0; i<r; i++) {
        for(int j=1; j<c; j++) {
            a[i][j] += a[i][j-1];
        }
    }
    for(int j=0; j<c; j++) {
        for(int i=1; i<r; i++) {
            a[i][j] += a[i-1][j];
        }
    }
    // for(int i=0; i<r; i++) {
    //     for(int j=0; j<c; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int q;
    cin >> q;
    while(q--) {
        int tli, tlj, bri, brj;
        cin >> tli >> tlj >> bri >> brj;
        cout << submatrixSum(&a, tli, tlj, bri, brj) << endl;
    }
    return 0;
}