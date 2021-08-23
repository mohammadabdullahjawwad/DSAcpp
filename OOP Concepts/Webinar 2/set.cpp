#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;
    s.insert(1);
    s.insert(5);
    s.insert(1);
    s.insert(5);
    s.insert(2);
    s.insert(3);
    for(auto x:s) {
        // cout << x << endl;
    }
    // Iterator
    for(set<int> :: iterator it = s.begin(); it!=s.end(); it++) {
        cout << *it << endl;
    }
    s.clear();
    cout << s.size() << endl;
    return 0;
}