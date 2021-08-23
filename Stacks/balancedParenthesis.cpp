#include <iostream>
#include <stack>
using namespace std;

bool balance(string str) {
    stack<char> s;
    for(int i=0; i<str.size(); i++) {
        if(str[i] == '(') {
            s.push(str[i]);
        }
        else if(str[i] == ')') {
            if(s.empty() || s.top() != '(') {
                return false;
            }
            s.pop();
        }
        else { // To ensure no other character was present
            return false;
        }
    }
    return s.empty();
}

int main() {
    string str;
    cin >> str;
    if(balance(str)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }
    return 0;
}