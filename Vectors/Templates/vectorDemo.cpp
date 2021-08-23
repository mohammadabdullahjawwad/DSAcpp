#include <iostream> // Used for standard classes
#include "vector.h" // Used for user defined classes
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
    Vector<char> v;
    v.push_back(71);
    v.push_back(72);
    v.push_back(73);
    v.push_back(74);
    v.pop_back();
    v.push_back(76);
    v.push_back(80);
    cout << "Capacity " << v.capacity() << endl;
    for (int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}