#include <iostream>
#include <stack>
using namespace std;

void stockSpan(int arr[], int n) {
    stack<int> s;
    int ans[n];
    for(int day=0; day<n; day++) {
        while(!s.empty() && arr[s.top()] <= arr[day]) {
            s.pop();
        }
        int better = s.empty() ? -1 : s.top();
        int span = day - better;
        ans[day] = span;
        s.push(day);
    }
    for(int i=0; i<n; i++) {
        cout << ans[i] << " ";
    }
    cout << "END" << endl;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    stockSpan(arr, n);
    return 0;
}