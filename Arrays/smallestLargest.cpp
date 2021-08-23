#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

pair<int, int> smallestLargest(vector<int> a) {
    int n = a.size();
    int small = INT_MAX;
    int large = INT_MIN;
    for(int i=0; i<n; i++) {
        small = min(small, a[i]);
        large = max(large, a[i]);
    }
    return {small, large};
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
    cout << smallestLargest(a).first << endl;
    cout << smallestLargest(a).second << endl;
    return 0;
}