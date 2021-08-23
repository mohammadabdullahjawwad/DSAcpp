#include <iostream>
#include <stack>
using namespace std;

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
    stack<int> s;
    int n;
    cin >> n;
    while(n--) {
        int val;
        cin >> val;
        s.push(val);
    }
    reverseStack(s);
    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}