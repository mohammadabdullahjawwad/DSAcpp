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

int makeChange(vi coins, int n, int money) {
    int ans = 0; // Stores the number of coins
    int value = money;
    while(money) {
        int index = upper_bound(coins.begin(), coins.end(), money) - coins.begin() - 1; // Returns the index of the largest coin with value smaller than money
        cout << coins[index] << " ";
        money -= coins[index];
        ans++;
    }
    cout << endl;
    return ans;
}

int main() {
    OJ;
    FIO;
    int money;
    cin >> money;
    vi coins = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int t = sizeof(coins)/sizeof(int);
    cout << makeChange(coins, t, money) << endl;
    return 0;
}