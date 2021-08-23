#include <bits/stdc++.h>
using namespace std;

int ans = 0;

void sum(int a[], int result[], int i, int key) {
    if(ans == key) {
        // Print the numbers
        return;
    }
    if(ans > key) {
        ans = 0;
        sum(a, result, i+1, key);
    }
    if(ans < key) {
        
    }

}

int main() {
    int n;
    cin >> n;
    int a[1000];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    int key;
    cin >> key;
    int result[1000] = {0};
    sum(a, result, 0, key);
    return 0;
}

// This problem in incomplete as of now