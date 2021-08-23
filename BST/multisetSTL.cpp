#include <iostream>
#include <set>
using namespace std;

typedef multiset<int>::iterator It;

int main() {
    int arr[] = {10, 20, 30, 20, 30, 30, 30, 10, 30};
    int n = sizeof(arr)/sizeof(int);
    
    multiset<int> m(arr, arr+n);
    
    m.erase(20);
    m.insert(80);
    
    for(int x:m) {
        cout << x << " ";
    }
    cout << endl;
    
    cout << m.count(10) << endl;
    
    auto it = m.find(30); // Will return the first element equal to the parameter
    cout << *it << endl;

    pair<It, It> range = m.equal_range(30);
    for(auto it = range.first; it != range.second; it++) {
        cout << *it << " ";
    }
    cout << endl;

    for(auto it=m.lower_bound(10); it != m.upper_bound(80); it++) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}