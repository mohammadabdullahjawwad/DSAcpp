#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void printMedian(int* a, int n) {
    priority_queue<int> max; // Stores lower half elements
    priority_queue<int, vector<int>, greater<int>> min; // Stores upper half elements
    int median = a[0];
    max.push(a[0]);
    cout << median << " ";
    for(int i=1; i<n; i++) {
        int x = a[i];
        // If max heap has more elements
        if(max.size() > min.size()) {
            if(x < median) {
                min.push(max.top());
                max.pop();
                max.push(x);
            }
            else {
                min.push(x);
            }
            median = (max.top() + min.top()) / 2;
        }
        // If both heaps have equal elements
        else if(max.size() == min.size()) {
            if(x < median) {
                max.push(x);
                median = max.top();
            }
            else {
                min.push(x);
                median = min.top();
            }
        }
        // If min heap has more elements
        else {
            if(x > median) {
                max.push(min.top());
                min.pop();
                min.push(x);
            }
            else {
                max.push(x);
            }
            median = (max.top() + min.top()) / 2;
        }
        cout << median << " ";
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for(int i=0; i<n; i++) {
            cin >> a[i];
        }
        printMedian(a, n);
        cout << endl;
    }
    return 0;
}