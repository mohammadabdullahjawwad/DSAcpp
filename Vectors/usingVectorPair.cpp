#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

bool compare(pair<int,int>& a, pair<int,int>& b) {
    int da = a.first * a.first + a.second * a.second;
    int db = b.first * b.first + b.second * b.second;
    if(da == db) {
        return a.first < b.first;
    }
    return da < db;
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    vector<pair<int, int>> cab(n);
    for(int i=0; i<n; i++) {
        cin >> cab[i].first >> cab[i].second;
    }
    sort(cab.begin(), cab.end(), compare);
    for(int i=0; i<n; i++) {
        cout << "(" << cab[i].first << ", " << cab[i].second << ")" << " ";
    }
    cout << endl;
    return 0;
}