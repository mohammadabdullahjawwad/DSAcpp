#include<iostream>
#include<algorithm>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void targetSumTriplets(int a[1000], int n, int key) {
    sort(a, a+n);
    for(int i=0; i<n; i++) {
        int *l = &a[i+1];
        int *r = &a[n-1];
        while(l<r) {
            if(a[i]+*l+*r == key) {
                cout << a[i] << ", " << *l << " and " << *r << endl;
                l++;
                r--;
            } else if(a[i]+*l+*r < key) {
                l++;
            } else {
                r--;
            }
        }
    }
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    int a[1000];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    int key;
    cin >> key;
    targetSumTriplets(a, n, key);
	return 0;
}