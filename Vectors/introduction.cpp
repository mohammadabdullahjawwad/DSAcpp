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

    // Creating and initalizing vectors
    vector<int> a;
    vector<int> b(5, 10); // no of elements = 5, value of all elements = 10
    vector<int> c(b.begin(), b.end()); // copy all elements of b
    vector<int> d{1, 2, 3, 10, 14}; // same as int* a = new int[5]{1, 2, 3, 10, 1}

    // Iterating over vectors
    // 1.
    for(int i=0; i<c.size(); i++) {
        cout << c[i] << " ";
    }
    cout << endl;
    // 2.
    for(vector<int>::iterator it=b.begin(); it!=b.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    // 3. For each loop
    for(int x: d) {
        cout << x << " ";
    }
    cout << endl;

    // Some more functions
    // 1. push_back()
    vector<int> v;
    int n;
    cin >> n;
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    for(int x: v) {
        cout << x << " ";
    }
    cout << endl;

    // Understanding at memory level the differences between the two vectors v and d defined above
    cout << v.size() << endl; // number of elements in the vector
    cout << v.capacity() << endl; // size of underlying array => returns 8
    cout << v.max_size() << endl; // max number of elements a vector can hold in the worst case according to the memory available in the system
    cout << d.size() << endl;
    cout << d.capacity() << endl; // => returns 5
    cout << d.max_size() << endl;

    return 0;
}