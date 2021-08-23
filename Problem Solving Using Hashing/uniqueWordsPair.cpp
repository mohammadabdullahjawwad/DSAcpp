#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define pub push_back
#define pob pop_back
#define mp make_pair
#define ll long long int
#define MOD 1000000007
#define clr(val) memset(val, 0, sizeof(val))

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

bool isPalindrome(string check) {
    if(!check.size()) {
        return true;
    }
    int l = 0;
    int r = check.size() - 1;
    while(l <= r) {
        if(check[l++] != check[r--]) {
            return false;
        }
    }
    return true;
}

vector<vector<int>> UniquePairs(vector<string>&str){
    unordered_map<string, int> us;
    set<vector<int>> ans;
    for(int i=0; i<str.size(); i++) {
        us[str[i]] = i;
    }
    for(int i=0; i<str.size(); i++) {
        // Prefix check
        string s = str[i];
        int s_len = s.length();
        for(int j=0; j<=s_len; j++) {
            string init = s.substr(0, j);
            reverse(init.begin(), init.end());
            if(us.count(init) && isPalindrome(s.substr(j, s_len))) {
                vector<int> v;
                v.pub(i);
                v.pub(us[init]);
                if(v[0] != v[1]) {
                    ans.insert(v);
                }
            }
            reverse(init.begin(), init.end());
        }
        // Suffix check
        for(int j=s_len; j>=0; j--) {
            string fin = s.substr(j, s_len);
            reverse(fin.begin(), fin.end());
            if(us.count(fin) && isPalindrome(s.substr(0, j))) {
                vector<int> v;
                v.pub(us[fin]);
                v.pub(i);
                if(v[0] != v[1]) {
                    ans.insert(v);
                }
            }
            reverse(fin.begin(), fin.end());
        }
    }
    vector<vector<int>> ret;
    for(auto it=ans.begin(); it!=ans.end(); it++) {
        vector<int> v = *(it);
        ret.pub(v);
    }
    return ret;
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    vector<string> str;
    for(int i=0; i<n; i++) {
        string x;
        cin >> x;
        str.pub(x);
    }
    vector<vector<int>> ans = UniquePairs(str);
    for(auto x:ans){
        vector<int> v = x;
        for(auto y:v) {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}