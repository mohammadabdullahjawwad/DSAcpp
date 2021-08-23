#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

// Recursion + Iteration
void bubbleSort(int a[], int n) {
    if(n == 1) {
        return;
    }
    for(int j=0; j<n-1; j++) {
        if(a[j] > a[j + 1]) {
            swap(a[j], a[j + 1]);
        }
    }
    bubbleSort(a, n - 1);
}

// Only recursion
void bubbleSortRec(int a[], int n, int j) {
    if(n == 1) {
        return;
    }
    if(j == n - 1) {
        bubbleSortRec(a, n - 1, 0);
        return;
    }
    if(a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
    }
    bubbleSortRec(a, n, j + 1);
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
    // bubbleSort(a, n);
    bubbleSortRec(a, n, 0);
    for(int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}