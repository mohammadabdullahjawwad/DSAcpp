#include <iostream>
using namespace std;
int search(int *a, int s, int e, int key) {
    // Base Case
    if(s > e) {
        return -1;
    }
    // Recursive Case
    int m = (s+e)/2;
    if(a[m] == key) {
        return m;
    }
    // Mid lies in the Left Part
    if(a[s] <= a[m]) {
        if(key>=a[s] && key<=a[m]) {
            return search(a, s, m-1, key);
        }
        return search(a, m+1, e, key);
    }
    // Mid lies in the Right Part
    if(key>=a[m] && key<=a[e]) {
        return search(a, m+1, e, key);
    }
    return search(a, s, m-1, key);
}
int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    int key;
    cin >> key;
    cout << search(a, 0, n-1, key) << endl;
    return 0;
}