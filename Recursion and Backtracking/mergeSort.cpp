#include <iostream>
using namespace std;

void merge(int a[], int s, int e) {

    int m = (s + e) / 2;
    int i = s;
    int j = m + 1;
    int k = s;

    int temp[100];

    while(i<=m && j<=e) {
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
    int m = (s + e) / 2;

    // 2.Recursive Sort - s,m and m+1,e
    mergeSort(a, s, m);
    mergeSort(a, m+1, e);

    // 3.Merge the two parts
    merge(a, s, e);
}

int main() {

    int a[100];
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    mergeSort(a, 0, n-1);

    for(int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;

}