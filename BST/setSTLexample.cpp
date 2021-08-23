#include <iostream>
#include <set>
#include <climits>
using namespace std;

int main() {

    set<pair<int, int>> s;
    
    s.insert(make_pair(10, 1));
    s.insert(make_pair(10, 5));
    s.insert(make_pair(20, 1));
    s.insert(make_pair(20, 100));
    s.insert(make_pair(5, 1));
    s.insert(make_pair(5, 3));
    s.insert(make_pair(5, 2));
    
    s.erase(s.find(make_pair(5, 3)));
    s.insert(make_pair(5, 4));

    auto it1 = s.lower_bound(make_pair(20, 1));
    cout << it1->first << " : " << it1->second << endl;

    auto it2 = s.upper_bound(make_pair(20, 1));
    cout << it2->first << " : " << it2->second << endl;

    auto it3 = s.upper_bound(make_pair(10, INT_MAX)); // Will give the pair for the highest value of first > 10
    cout << it3->first << " : " << it3->second << endl;

    cout << endl;

    for(auto p:s) {
        cout << p.first << " : " << p.second << endl;
    }
    return 0;
}