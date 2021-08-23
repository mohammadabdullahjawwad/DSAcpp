#include <iostream>
using namespace std;

int length;

void allIndices(int a[], int n, int key) {
    if(n == 0) {
        return;
    }
    if(a[length-n] == key) {
        cout << length-n << " ";
    }
    allIndices(a, n-1, key);
}

int main() {
    int n;
    cin >> n;
    length = n;
    int a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    int key;
    cin >> key;
    allIndices(a, n, key);
    cout << endl;
    return 0;
}