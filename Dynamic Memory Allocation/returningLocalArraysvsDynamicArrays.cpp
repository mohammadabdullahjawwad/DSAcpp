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

// int* fun() {
//     int a[] = {1, 2, 3, 4, 5};
//     cout << a << endl;
//     cout << a[0] << endl;
//     return a; // Gets destroyed as soon as function call is over as it is a static array. We should never return (the address of) a local variable. Create a dynamic array instead
// }

int* fun() {
    int *a = new int[5];
    a[0] = 11;
    a[1] = 2;
    cout << a << endl;
    cout << a[0] << endl;
    return a; // It works now because, being a dynamic array, it can be returned. Only the pointer is deleted when function call is over, not the actual array. This is because it does not get destroyed unless the user deletes it. Now since b points to the array, even if the pointer a gets deleted, we can still access the array through the pointer b
}

int main() {
    OJ;
    FIO;
    int *b = fun();
    cout << b << endl;
    cout << b[0] << endl;
    delete [] b; // This deletes the the array a.
    return 0;
}