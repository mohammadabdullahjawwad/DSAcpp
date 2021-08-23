#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i=0; i<n; i++) {
        cin >> h[i];
    }
    int* left = new int[n];
    left[0] = h[0];
    for(int i=1; i<n; i++) {
        left[i] = max(left[i-1], h[i]);
    }
    int* right = new int[n];
    right[n-1] = h[n-1];
    for(int i=n-2; i>=0; i--) {
        right[i] = max(right[i+1], h[i]);
    }
    int water = 0;
    for(int i=0; i<n; i++) {
        water += min(left[i], right[i]) - h[i];
    }
    cout << water << endl;
    return 0;
}