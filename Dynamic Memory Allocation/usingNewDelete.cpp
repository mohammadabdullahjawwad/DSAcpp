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

int main() {
    OJ;
    FIO;

    // Static Allocation
    int b[100] = {0}; // Initialising with all zeros
    cout << sizeof(b) << endl;
    cout << b << endl;

    // Dynamic Allocation
    int n;
    cin >> n;
    int* a = new int[n]{0}; // Initialising with all zeros
    cout << sizeof(a) << endl; // It is actually the size of pointer pointing to array
    cout << a << endl;

    for(int i=0; i<n; i++) {
        cin >> a[i];
        cout << a[i];
    }

    // Free up space
    delete [] a;

    return 0;
}