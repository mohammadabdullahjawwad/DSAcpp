#include <iostream>
#include <algorithm>
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
    // find() = STL implementation of linear search
    int arr[] = {1, 10, 11, 9, 100};
    int n = sizeof(arr)/sizeof(int);

    int key;
    cin >> key;

    auto it = find(arr, arr+n, key);
    int index = it - arr; // Subtracting 2 addresses gives us the no of locations between them in C++. Here it gives the required index
    if(index == n) {
        cout << key << " not present" << endl;
    }
    else {
        cout << key << " present at index " << index << endl;
    }
    return 0;
}