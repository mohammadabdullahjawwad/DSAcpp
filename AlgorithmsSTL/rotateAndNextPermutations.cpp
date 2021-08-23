#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int idx;
    cin >> idx;

    // Rotate an array
    rotate(arr.begin(), arr.begin() + idx, arr.end()); // Rotates array about idx. Brings elements from indices [idx, n) to front then elements from indices [0, idx)
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Next lexicographically bigger permutation (arrangement) of elements in an array
    next_permutation(arr.begin(), arr.end());

    // For each loop
    for(int x: arr) {
        cout << x << " ";
    }
    cout << endl;
}

// void solve() {
//     int n;
//     cin >> n;
//     int arr[n];
//     for(int i=0; i<n; i++) {
//         cin >> arr[i];
//     }
//     int idx;
//     cin >> idx;
//     rotate(arr, arr + idx, arr + n);
//     for(int i=0; i<n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

int main() {
    OJ;
    FIO;
    solve();
    return 0;
}