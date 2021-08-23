#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int partition(int *a, int s, int e) { // Doing it in place
    int i = s - 1; // Initially there is no smaller region. Hence we start from -1 in the very first function call
    int j = s;
    int p = a[e]; // We make the last element as pivot
    for(; j<e; j++) {
        if(a[j] <= p) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[e], a[i + 1]); // To place the pivot int the correct place
    return i + 1; // Return the index of pivot element
}

// Points worth noting :
// 1. Quicksort is divide & conquer
// 2. Time Complexity = O(NlogN) for avg case
// 3. It is O(n * n) for worst case but can be fixed using randomised quick sort
// 4. It is an in place algorithm. Although it requires extra space due to recursion call stack
void quickSort(int* a, int s, int e) {
    if(s >= e) {
        return;
    }
    int p = partition(a, s, e);
    quickSort(a, s, p - 1);
    quickSort(a, p + 1, e);
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
    quickSort(a, 0, n - 1);
    for(int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}