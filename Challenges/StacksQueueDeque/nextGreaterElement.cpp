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

void great(vector<int>& in, int n) {
    stack<int> s;
    vector<int> out(n, -1);
    // fill_n(out, n, -1); // Alternate way of assigning same value to all elements of an array. We can use memset too.
    for(int i = 2 * n - 1; i >= 0; i--) {
        while(!s.empty() && in[s.top()] <= in[i % n]) {
            s.pop();
        }
        if(!s.empty()) {
            out[i % n] = in[s.top()];
        }
        s.push(i % n);
    }
    for(int i = 0; i < n; i++) {
        cout << out[i] << " ";
    }
    cout << endl;
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    vector<int> in(n);
    for(int i = 0; i < n; i++) {
        cin >> in[i];
    }
    great(in, n);
    return 0;
}