#include <iostream>
#include <vector>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int linearSearch(vector<int> a, int key) {
    int n = a.size();
    for(int i=0; i<n; i++) {
        if(a[i] == key) {
            return i;
        }
    }
    return -1;
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
    int key;
    cin >> key;
    cout << linearSearch(a, key) << endl;
    return 0;
}