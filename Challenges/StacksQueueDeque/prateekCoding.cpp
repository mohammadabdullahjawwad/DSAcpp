#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    int q;
    cin >> q;
    while(q--) {
        int type;
        cin >> type;
        if(type == 2) {
            int cost;
            cin >> cost;
            s.push(cost);
        }
        else if(type == 1) {
            if(s.empty()) {
                cout << "No Code" << endl;
            }
            else {
                cout << s.top() << endl;
                s.pop();
            }
        }
    }
    return 0;
}