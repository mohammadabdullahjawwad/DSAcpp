#include<iostream>
#include <vector>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

bool compare(int a, int b) {
    return a > b;
}

void bubbleSort(vector<int>& a, bool (&compare)(int a, int b)) { // Passing function as a parameter to another function
    int n = a.size();
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(compare(a[j], a[j+1])) {
                swap(a[j], a[j+1]);
            }
        }
    }
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    bubbleSort(a, compare);
    for(int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}