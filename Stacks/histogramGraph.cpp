#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

int histogram(vector<int>& a, int n) {
    stack<int> s;
    int maxarea = 0;
    int i = 0;
    while(i < n) {
        if(s.empty() || a[i] >= a[s.top()]) {
            s.push(i++);
        }
        else {
            int height = s.top();
            s.pop();
            int area = a[height] * (s.empty() ? i : (i - s.top() - 1));
            if(maxarea < area) {
                maxarea = area;
            }
        }
    }
    while(!s.empty()) {
        int height = s.top();
        s.pop();
        int area = a[height] * (s.empty() ? i : (i - s.top() - 1));
        if(maxarea < area) {
            maxarea = area;
        }
    }
    return maxarea;
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << histogram(a, n) << endl;
    return 0;
}