#include <iostream>
#include <list> // list is STL implementation of doubly linked list
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

    list<int> l;

    // Initialisation
    list<int> l1{1, 2, 3, 10, 8, 5};

    list<string> l2{"apple", "guava", "mango", "banana"};
    l2.push_back("pineapple");

    // Sorting of elements
    l2.sort();

    // Reverse the ordering
    l2.reverse();

    // Remove first (front) element
    cout << l2.front() << endl;
    l2.pop_front();

    // Adding to front
    l2.push_front("kiwi");

    // Remove from back
    cout << l2.back() << endl;
    l2.pop_back();

    // Iterate over and print data
    for(auto it = l2.begin(); it != l2.end(); it++) {
        cout << *it << "->";
    }
    cout << "NULL" << endl;
    for(string s: l2) {
        cout << s << "->";
    }
    cout << "NULL" << endl;

    l2.push_back("orange");
    l2.push_back("guava");
    for(string s: l2) {
        cout << s << "->";
    }
    cout << "NULL" << endl;

    // remove all occurrences of an element
    string f;
    cin >> f;
    l2.remove(f);
    for(string s: l2) {
        cout << s << "->";
    }
    cout << "NULL" << endl;
    
    // erase one or more elements
    // auto it = l2.begin() + 3; // We cannot access an element directly in a linked list. Hence this won't work
    auto it = l2.begin();
    it++;
    it++;
    l2.erase(it);
    for(string s: l2) {
        cout << s << "->";
    }
    cout << "NULL" << endl;

    // Insert an element
    it = l2.begin();
    it++;
    l2.insert(it, "papaya");
    for(string s: l2) {
        cout << s << "->";
    }
    cout << "NULL" << endl;
 
    return 0;
}