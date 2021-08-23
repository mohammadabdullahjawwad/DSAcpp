#include <iostream>
#include <set>
using namespace std;

int main() {
    int arr[] = {10, 20, 11, 9, 8, 11, 10};
    int n = sizeof(arr)/sizeof(arr[0]);

    set<int> s;
    for(int i=0; i<n; i++) {
        s.insert(arr[i]);
    }
    // 2 ways to erase an element
    s.erase(10); // First way
    auto it = s.find(11); // Second way
    s.erase(it);
    for(set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *(it) << " "; // By default these elements are ordered
    }
    cout << endl;
    return 0;
}