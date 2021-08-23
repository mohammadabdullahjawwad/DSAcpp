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

vector<vector<int>> subarray(vector<int>& a) {
    int n = a.size();
    vector<vector<int>> ans;
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            vector<int> v;
            for(int k=i; k<=j; k++) {
                v.push_back(a[k]);
            }
            ans.push_back(v);
        }
    }
    return ans;
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
    vector<vector<int>> ans = subarray(a);
    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}