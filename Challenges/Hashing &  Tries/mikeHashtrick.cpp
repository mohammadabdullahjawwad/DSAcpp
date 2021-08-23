#include <iostream>
#include <vector>
#include <string.h>
#include <unordered_map>
#include <algorithm>
using namespace std;

#define vi vector<int>
#define pii pair<int ,int>
#define all(v) v.begin(), v.end()
#define mp make_pair
#define ll long long int
#define MOD 1000000007
#define clr(val) memset(val,0,sizeof(val))

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

unordered_map<int, int> m;

bool compare(int a, int b) {
    return m[a] < m[b];
}

vi Hashtrick(int* a, int n) {
    vi v;
    for(int i=0; i<n; i++) {
        if(m.find(a[i]) == m.end()) {
            v.push_back(a[i]);
        }
        m[a[i]] = i;
    }
    sort(all(v), compare);
    return v;
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    int *a = new int[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    vi v = Hashtrick(a, n);
    for(auto it:v) {
        cout << it << endl;
    }
    return 0;
}