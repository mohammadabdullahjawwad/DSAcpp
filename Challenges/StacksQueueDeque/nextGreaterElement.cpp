#include <iostream>
#include <stack>
using namespace std;

void great(int in[], int n) {
    stack<int> s;
    int out[n];
    // for(int i=0; i<n; i++) {
    //     out[i] = -1;
    // }
    fill_n(out, n, -1); // Alternate way of assigning same value to all elements of an array. We can use memset too.
    for(int i=2*n-1; i>=0; i--) {
        while(!s.empty() && in[s.top()] <= in[i%n]) {
            s.pop();
        }
        if(!s.empty()) {
            out[i%n] = in[s.top()];
        }
        s.push(i%n);
    }
    for(int i=0; i<n; i++) {
        cout << out[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int in[1000002];
    for(int i=0; i<n; i++) {
        cin >> in[i];
    }
    great(in, n);
    return 0;
}