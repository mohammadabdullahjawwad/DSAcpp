#include <iostream>
#include <stack>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void stockSpan(int arr[], int n) {
    stack<int> s;
    int ans[n];
    for(int day = 0; day < n; day++) {
        while(!s.empty() && arr[s.top()] <= arr[day]) {
            s.pop();
        }
        int better = s.empty() ? -1 : s.top();
        int span = day - better;
        ans[day] = span;
        s.push(day);
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "END" << endl;
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    stockSpan(arr, n);
    return 0;
}