#include <iostream>
#include <vector>
#include <unordered_map>
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

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int lengthLongestSumZero(int *a, int n) {
    unordered_map<int, int> m;
    int ans = 0;
    int pre = 0;
    for(int i=0; i<n; i++) {
        pre += a[i];
        // If there is one index i such that a[i] = 0 and there is subarray till now for which sum is 0
        if(a[i] == 0 && ans == 0) {
            ans = 1;
        }
        // If prefix sum till index i = 0, the subarray sum from start to i will be 0
        if(pre == 0) {
            ans = max(ans, i+1);
        }
        // If the prefix value is already present in m
        if(m.count(pre)) {
            ans = max(ans, i - m[pre]);
        }
        else {
            m[pre] = i;
        }
    }
    return ans;
}

int main() {
    OJ;
    int n;
    cin >> n;
    int *a = new int[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    cout << lengthLongestSumZero(a, n) << endl;
    return 0;
}