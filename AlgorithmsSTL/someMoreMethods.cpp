#include <iostream>
#include <algorithm>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void solve() {
    
    int a, b;
    cin >> a >> b;
    cout << a << " " << b << endl;
    
    swap(a, b);
    cout << a << " " << b << endl;

    cout << max(a, b) << endl;
    cout << min(a, b) << endl;

    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int idx;
    cin >> idx;

    reverse(arr, arr + idx); // reverses array indices [0, idx)
    
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}

int main() {
    OJ;
    FIO;
    solve();
    return 0;
}