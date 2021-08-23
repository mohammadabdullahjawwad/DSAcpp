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

// Pass by Value
// void increment(int a) {
//     a = a + 1;
//     cout << "Inside function " << a << endl;
// }

// Pass by Reference using Pointers
void increment(int* aptr) {
    *aptr = *aptr+ 1;
    cout << "Inside function " << *aptr << endl;
}

int main() {
    OJ;
    FIO;
    ll t;
    int a = 10;
    // increment(a);
    increment(&a);
    cout << "Inside main " << a << endl;
    return 0;
}