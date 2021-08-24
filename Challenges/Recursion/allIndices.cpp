#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void allIndices(int a[], int n, int i, int key) {
    if(i == n) {
        return;
    }
    if(a[i] == key) {
        cout << i << " ";
    }
    allIndices(a, n, i + 1, key);
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    int key;
    cin >> key;
    allIndices(a, n, 0, key);
    cout << endl;
    return 0;
}