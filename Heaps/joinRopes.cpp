#include <iostream>
#include <vector>
#include <queue> // Heap STL is present in queue header file
using namespace std;

int joinRopesMinCost(int* ropes, int n) {
    priority_queue<int, vector<int>, greater<int>> pq(ropes, ropes + n); // Min heap implementation syntax in C++ STL with constructor initialisation
    int cost = 0;
    while(pq.size() > 1) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        cost += (first + second);
        pq.push(first+second);
    }
    return cost;
}

int main() {
    int n;
    cin >> n;
    int* a = new int[n](); // () initialises whole array with 0
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    cout << joinRopesMinCost(a, n) << endl;
    return 0;
}