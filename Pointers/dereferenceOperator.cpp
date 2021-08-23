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
    int x = 10;
    int* xptr;
    xptr = &x;
    
    cout << &x << endl;
    cout << xptr << endl;
    
    cout << *(&x) << endl;
    cout << *(xptr) << endl;

    cout << *(&xptr) << endl;
    cout << &(*xptr) << endl;

    cout << &xptr << endl;
    int **xxptr = &xptr; // Double pointer
    cout << xxptr << endl;

    return 0;
}