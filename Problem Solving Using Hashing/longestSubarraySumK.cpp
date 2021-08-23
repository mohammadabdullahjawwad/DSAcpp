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

int lengthLongestSumK(int *a, int n, int k) {
    unordered_map<int, int> m;
    int ans = 0;
    int pre = 0;
    for(int i=0; i<n; i++) {
        pre += a[i];
        // If there is one index i such that a[i] = k and there is no subarray till now for which sum is k
        // if(a[i] == k && ans == 0) {
        //     ans = 1;
        // }
        // If prefix sum till index i is k, the subarray sum from start to i will be k
        if(pre == k) {
            ans = max(ans, i+1);
        }
        // If the prefix value is already present in m
        if(m.count(pre - k)) {
            ans = max(ans, i - m[pre - k]);
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
    int k;
    cin >> k;
    cout << lengthLongestSumK(a, n, k) << endl;
    return 0;
}