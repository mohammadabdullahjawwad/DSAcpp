#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <climits>
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

int loadBalancing(int *arr, int n) {
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
    }
    if(sum%n != 0) {
        return -1;
    }
    int avg = sum / n;
    int ans = INT_MIN;
    int val = 0;
    for(int i=0; i<n; i++) {
        val += (arr[i] - avg);
        ans = max(ans, abs(val));
    }
    return ans;
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout<< loadBalancing(arr, n) << endl;
    return 0;
}