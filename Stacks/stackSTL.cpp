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
    for(int i =0; i<=5; i++) {
        s.push(i);
    }
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
    return 0;
}