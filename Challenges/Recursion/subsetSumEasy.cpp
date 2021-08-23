#include <iostream>
using namespace std;

int count = 0, sum = 0;

void subsetSum(int* a, int n, int sum, int i) {
    if(i == n) {
        if(sum == 0) {
            count++;
        }
        sum = 0;
        return;
    }
    subsetSum(a, n, sum, i+1);
    sum += a[i];
    subsetSum(a, n, sum, i+1);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n];
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        int sum = 0;
        subsetSum(a, n, sum, 0);
        if(count > 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}

// As of now the problem is incomplete