#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[] = {0, 1, 2, 2, 2, 2, 2, 2, 3, 4};
    int n = sizeof(arr) / sizeof(int);
    auto first = lower_bound(arr, arr+n, 2) - arr; // Gives the index of the lower bound of 2 in arr because we subtract the address of a[0] from the address of the lower bound of 2 
    auto last = upper_bound(arr, arr+n, 2) - arr - 1; // We subtract 1 because it otherwise gives the index after the upper bound of 2 originally
    cout << first << endl << last << endl;
    return 0;
}

// Time complexity of program - O(logN)