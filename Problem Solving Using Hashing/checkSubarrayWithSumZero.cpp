#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

#define vi vector<int>
#define pii pair<int ,int>
#define all(v) v.begin(), v.end()
#define pub push_back
#define pob pop_back
#define mp make_pair
#define ll long long int
#define MOD 1000000007
#define clr(val) memset(val,0,sizeof(val))

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);

bool checkSubarrayWithSumZero(int *a, int n) {
    unordered_set<int> s;
    int pre = 0;
    for(int i=0; i<n; i++) {
        pre += a[i];
        if(!pre || s.find(pre) != s.end()) {
            return true;
        }
        s.insert(pre);
    }
    return false;
}

int main() {
    OJ;
    int n;
    cin >> n;
    int * a = new int[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    bool b = checkSubarrayWithSumZero(a, n);
    if(b) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}