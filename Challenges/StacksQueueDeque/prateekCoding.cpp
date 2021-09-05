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

int main() {
    OJ;
    FIO;
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