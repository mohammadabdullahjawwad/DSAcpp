#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void merge(int a[], int s, int e) {

    int m = s + (e - s) / 2;
    int i = s;
    int j = m + 1;
    int k = s;

    int temp[100];

    while(i <= m && j <= e) {
        if(a[i] < a[j]) {
            temp[k++] = a[i++];
        }
        else {
            temp[k++] = a[j++];
        }
    }
    while(i <= m) {
        temp[k++] = a[i++];
    }
    while(j <= e) {
        temp[k++] = a[j++];
    }

    // Copy all elements to original array
    for(int i=s; i<=e; i++) {
        a[i] = temp[i];
    }
}

void mergeSort(int a[], int s, int e) {
    // Base Case - 1 or 0 elements
    if(s >= e) {
        return;
    }

    // Follow 3 steps
    // 1.Divide
    int m = s + (e - s) / 2;

    // 2.Recursively Sort - [s, m] and [m + 1, e]
    mergeSort(a, s, m);
    mergeSort(a, m + 1, e);

    // 3.Merge the two parts
    merge(a, s, e);
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

    mergeSort(a, 0, n - 1);

    for(int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;

}