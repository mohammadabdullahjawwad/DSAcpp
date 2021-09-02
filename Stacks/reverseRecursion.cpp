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

void insertAtBottom(stack<int> &s, int x) {
    if(s.empty()) {
        s.push(x);
        return;
    }
    int n = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(n);
}

void reverseStack(stack<int> &s) {
    if(s.empty()) {
        return;
    }
    int x = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, x);
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