// For first occurrence
#include <iostream>
using namespace std;
int binarySearch(int *a, int n, int key) {
    int s = 0;
    int e = n-1;
    int ans = -1;
    while(s <= e) {
        int m = (s+e)/2;
        if(key == a[m]) {
            ans = m;
            e = m-1;
        } else if(key > a[m]) {
            s = m+1;
        } else {
            e = m-1;
        }
    }
    return ans;
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
    int index = binarySearch(a, n, key);
    if(index == -1) {
        cout << key << " is not present" << endl;
    } else {
        cout << "First occurrence of " << key << " is index " << index << endl;
    }
    return 0;
}

// For last occurrence
#include <iostream>
using namespace std;
int binarySearch(int *a, int n, int key) {
    int s = 0;
    int e = n-1;
    int ans = -1;
    while(s <= e) {
        int m = (s+e)/2;
        if(key == a[m]) {
            ans = m;
            s = m+1;
        } else if(key > a[m]) {
            s = m+1;
        } else {
            e = m-1;
        }
    }
    return ans;
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
    int index = binarySearch(a, n, key);
    if(index == -1) {
        cout << key << " is not present" << endl;
    } else {
        cout << "Last occurrence of " << key << " is index " << index << endl;
    }
    return 0;
}