#include<iostream>
#include<algorithm>
#include <unordered_map>
#include <unordered_set>
#include <utility>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void targetSumPair(int a[1000], int n, int key) {
    sort(a, a+n);
    int *l;
    int *r;
    l = &a[0];
    r = &a[n-1];
    while(l < r) {
        if(*l+*r == key) {
            cout << *l << " and " << *r << endl;
            l++;
            r--;
        } else if(*l+*r < key) {
            l++;
        } else {
            r--;
        }
    }
}

void targetSumPair2(int *a, int n, int key) {
    bool found[n] = {false};
    unordered_map<int, int> m;
    for(int i=0; i<n; i++) {
        m[a[i]] = i;
    }
    for(int i=0; i<n; i++) {
        int check = key - a[i];
        if(m[check] && m[check] != i) {
            if(!found[i] && !found[m[check]]) {
                cout << min(a[i], check) << " and " << max(a[i], check) << endl;
                found[i] = true;
                found[m[check]] = true;
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
    targetSumPair(a, n, key);
    targetSumPair2(a, n, key);
	return 0;
}