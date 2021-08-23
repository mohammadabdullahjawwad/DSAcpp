#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int kadane(int *a, int n) {
    int max_sum = 0, current_sum = 0;
    for(int i=0; i<n; i++) {
        current_sum += a[i];
        if(current_sum < 0) {
            current_sum = 0;
        }
        if(max_sum < current_sum) {
            max_sum = current_sum;
        }
    }
    return max_sum;
}

int maxCircularSum(int *a, int n) {
    int max_kadane = kadane(a, n);
    int max_wrap = 0;
    for(int i=0; i<n; i++) {
        max_wrap += a[i];
        a[i] = -a[i];
    }
    max_wrap += kadane(a, n);
    return max(max_wrap, max_kadane);
}

int main() {
    OJ;
    FIO;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        cout << maxCircularSum(a, n) << endl;
    }
    return 0;
}