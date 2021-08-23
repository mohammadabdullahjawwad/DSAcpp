#include <iostream>
#include <vector>
#include <set>
#include <map>
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
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

// Not accepted in leetcode - TLE
int approach1(int *a, int n) {
    set<int> m;
    for(int i=0; i<n; i++) {
        m.insert(a[i]);
    }
    int minimum = 0;
    int maximum = 0;
    for(int i=0; i<n; i++) {
        minimum = min(minimum, a[i]);
        maximum = max(maximum, a[i]);
    }
    int ans = 0;
    int count = 0;
    for(int i=minimum; i<=maximum; i++) {
        if(m.count(i)) {
            count++;
        }
        else {
            ans = max(count, ans);
            count = 0;
        }
    }
    ans = max(count, ans);
    return ans;
}

// Not getting correct answer
int approach2(int *a, int n) {
    map<int, int> m;
    int ans = 0;
    int val[n];
    clr(val);
    for(int i=0; i<n; i++) {
        int lenl = 0;
        int lenr = 0;
        if(m.count(a[i]-1)) {
            lenl = m[a[i]-1] + 1;
        }
        if(m.count(a[i]+1)) {
            lenr = m[a[i]+1] + 1;
        }
        int streak = 1+lenl+lenr;
        if(!m.count(a[i])) {
            m.insert(mp(a[i], streak));
        }
        m[a[i]-lenl] = streak;
        m[a[i]+lenr] = streak;
        ans = max(ans, streak);
    }
    return ans;
}

// Accepted in leetcode :)
int approach3(int *a, int n) {
    unordered_set<int> m;
    for(int i=0; i<n; i++) {
        m.insert(a[i]);
    }
    int ans = 0;
    for(int i=0; i<n; i++) {
        if(m.find(a[i]-1) != m.end()) {
            continue;
        }
        else {
            int count = 0;
            int x = a[i]; // Left Boundary
            while(m.find(x) != m.end()) {
                count++;
                x += 1;
            }
            ans = max(ans, count);
        }
    }
    return ans;
}

int main() {
    OJ;
    int n;
    cin >> n;
    int *a = new int[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    cout << approach1(a, n) << endl;
    cout << approach2(a, n) << endl;
    cout << approach3(a, n) << endl;
    return 0;
}