#include <iostream>
#include <vector>
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
    vector<int> d{1, 2, 3, 10, 14};

    // push_back() => O(1) for most of the time
    d.push_back(16);

    // pop_back() => O(1)
    d.pop_back();

    // insert elements in the middle => O(n) where n = no of elements added + shifted
    d.insert(d.begin() + 3, 4, 100); // 100 is added at index 3. Second parameter i.e. 4 adds 4 elements starting at index 3. This paramenter is optional, if we do not give this parameter, it will add one element. All remaining elements are pushed one index ahead

    // erase elements from middle
    d.erase(d.begin() + 3, d.begin() + 5); // erases element at index 3 and shifts all remaining elements to the left. The second optional parameter helps delete delete elements in the range [3, 5) here

    // size()
    cout << d.size() << endl;

    // capacity()
    cout << d.capacity() << endl;

    // resize() - changes the size but the capacity increases only if we increase the size during resize. It never decreases
    d.resize(8);
    cout << d.size() << endl;
    cout << d.capacity() << endl;

    // clear() - removes all elements (size = 0). It does not delete the memory occupied by the array
    d.clear();
    cout << d.size() << endl;

    // empty() - check whether vector is empty or not
    if(d.empty()) {
        cout << "empty vector" << endl;
    }

    //  front() - returns the first element. back() - returns the last element
    d.push_back(10);
    d.push_back(11);
    d.push_back(12);
    cout << d.front() << endl;
    cout << d.back() << endl;

    for(int x: d) {
        cout << x << " ";
    }
    cout << endl;

    // reserve() - to avoid doubling which is an expensive operation
    int n;
    cin >> n;
    vector<int> v;
    v.reserve(1000); // makes capacity = 1000
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    for(int x: v) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}