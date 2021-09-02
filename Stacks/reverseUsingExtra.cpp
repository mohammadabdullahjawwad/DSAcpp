#include <iostream>
#include <stack>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void transfer(stack<int> &s1, stack<int> &s2, int n) {
    for(int i=0; i<n; i++) {
        s2.push(s1.top());
        s1.pop();
    }
}

void reverseStack(stack<int> &s1) {
    stack<int> s2;
    int n = s1.size();
    for(int i=0; i<n; i++) {
        int x = s1.top();
        s1.pop();
        transfer(s1, s2, n - i - 1);
        s1.push(x);
        transfer(s2, s1, n - i - 1);
    }
}

int main() {
    OJ;
    FIO;
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    reverseStack(s);
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    return 0;
}