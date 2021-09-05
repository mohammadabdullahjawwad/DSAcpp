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

bool balance(string str) {
    stack<char> s;
    for(int i = 0; i < str.size(); i++) {
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
    OJ;
    FIO;
    string str;
    cin >> str;
    if(balance(str)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}