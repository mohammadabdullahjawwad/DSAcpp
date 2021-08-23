#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string.h>
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

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    int *a = new int[n];
    unordered_map<int, int> ua;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        ua[a[i]]++;
    }
    int *b = new int[n];
    unordered_map<int, int> ub;
    for(int i=0; i<n; i++) {
        cin >> b[i];
        ub[b[i]]++;
    }
    vi ans;
    for(int i=0; i<n; i++) {
        if(ua.find(a[i]) != ua.end() && ub.find(a[i]) != ub.end()) {
            while(ua[a[i]] && ub[a[i]]) {
                ans.push_back(a[i]);
                ua[a[i]]--;
                ub[a[i]]--;
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << "[";
    for(int i=0; i<ans.size()-1; i++) {
        cout << ans[i] << ", ";
    }
    cout << ans[ans.size()-1] << "]" << endl;
    return 0;
}