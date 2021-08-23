#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void allOcc(int a[], int i, int n, int key) {
    if(i == n) {
        return;
    }
    if(a[i] == key) {
        cout << i << " ";
    }
    allOcc(a, i + 1, n, key);
}

int storeOcc(int* a, int i, int n, int key, int* out, int j) {
    if(i == n) {
        return j;
    }
    if(a[i] == key) {
        out[j] = i;
        return storeOcc(a, i + 1, n, key, out, j + 1);
    }
    return storeOcc(a, i + 1, n, key, out, j);
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
    // allOcc(a, 0, n, key);
    // cout << endl;
    int output[100];
    int cnt = storeOcc(a, 0, n, key, output, 0);
    cout << "Count : " << cnt << endl;
    for(int i=0; i<cnt; i++) {
        cout << output[i] << " ";
    }
    cout << endl;
    return 0;
}