#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int merge(int* a, int s, int e) {
    int mid = s + (e - s) / 2;
    int i = s;
    int j = mid + 1;
    int k = s;
    int temp[10000];
    int cnt = 0; // No of cross inversions
    while(i <= mid && j <= e) {
        if(a[i] <= a[j]) {
            temp[k++] = a[i++];
        }
        else {
            temp[k++] = a[j++];
            cnt += mid - i + 1; // All elements a[i] to a[mid] will form inversions with a[j]
        }
    }
    while(i <= mid) {
        temp[k++] = a[i++];
    }
    while(j <= e) {
        temp[k++] = a[j++];
    }
    for(int i=s; i<=e; i++) {
        a[i] = temp[i];
    }
    return cnt;
}

int inversionCount(int* arr, int s, int e) {
    // Base Case - No inversions if there's a single element
    if(s >= e) {
        return 0;
    }
    // Merge Sort
    int m = s + (e - s) / 2;
    int x = inversionCount(arr, s, m); // No of inversions in the first half
    int y = inversionCount(arr, m + 1, e); // No of inversions in the second half
    int z = merge(arr, s, e); // No of cross inversions
    return x + y + z;
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    int* a = new int[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    // Sorting will not affect the number of cross inversions
    cout << inversionCount(a, 0, n - 1) << endl;
    return 0;
}