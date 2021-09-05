#include <iostream>
#include <deque>
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
    long long int n;
    cin >> n;
    long long int a[n];
    for(long long int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long int k;
    cin >> k;
    // Process first k elements separately
    deque<long long int> q(k);
    long long int i;
    for(i = 0; i < k; i++) {
        while(!q.empty() && a[i] > a[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
    }
    // Process the remaining elements
    for(; i < n; i++) {
        cout << a[q.front()] << " ";
        // Remove the elements not a part of the window
        while(!q.empty() && q.front() <= i - k) {
            q.pop_front();
        }
        // Remove the elements that are not useful and are a part of the window
        while(!q.empty() && a[i] >= a[q.back()]) {
            q.pop_back();
        }
        // Add new elements
        q.push_back(i);
    }
    cout << a[q.front()] << endl;
    return 0;
}