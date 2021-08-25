#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

bool subsetSum(int* a, int n, int sum, int flag, int i) {
    if(i == n) {
        if(sum == 0 && flag > 0) {
            return true;
        }
        return false;
    }
    return subsetSum(a, n, sum, flag, i + 1) || subsetSum(a, n, sum + a[i], flag + 1, i + 1);
}

int main() {
    OJ;
    FIO;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n];
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        int flag = 0;
        int ans = subsetSum(a, n, 0, flag, 0);
        if(ans) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout << endl;
    }
    return 0;
}