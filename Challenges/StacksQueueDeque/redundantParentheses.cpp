#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

void redundant(string str) {
    stack<char> s;
    for(char ch : str) {
        if(ch == ')') {
            char top = s.top();
            s.pop();
            int count = 0;
            while(top != '(') {
                count++;
                top = s.top();
                s.pop();
            }
            if(count == 0) {
                cout << "Duplicate" << endl;
                return;
            }
        }
        else {
            s.push(ch);
        }
    }
    cout << "Not Duplicates" << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        redundant(str);
    }
    return 0;
}