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
    int **arr;
    int r, c;
    cin >> r >> c;

    // Create an array of rowheads
    arr = new int*[r];
    
    // Create a 2D array
    for(int i = 0; i < r; i++) {
        arr[i] = new int[c];
    }

    // Take input and print the elements
    int val = 1;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            arr[i][j] = val;
            val++;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}