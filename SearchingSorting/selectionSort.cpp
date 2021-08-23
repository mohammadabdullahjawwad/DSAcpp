#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void selectionSort(vector<int>& a, int n) {
    for(int i=0; i<n-1; i++) {
        int minIndex = i;
        for(int j=i+1; j<n; j++) {
            if(a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        swap(a[minIndex], a[i]);
    }
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    vector<int> a;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    selectionSort(a, n);
    for(int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}