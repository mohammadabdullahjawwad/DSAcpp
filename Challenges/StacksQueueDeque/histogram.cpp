#include <iostream>
#include <stack>
using namespace std;

long long int histogram(long long int a[], int n) {
    stack<int> s;
    long long int maxarea = 0;
    int i = 0;
    while(i < n) {
        if(s.empty() || a[i] >= a[s.top()]) {
            s.push(i++);
        }
        else {
            int height = s.top();
            s.pop();
            long long int area = a[height] * (s.empty() ? i : (i-s.top()-1));
            if(maxarea < area) {
                maxarea = area;
            }
        }
    }
    while(!s.empty()) {
        int height = s.top();
        s.pop();
        int area = a[height] * (s.empty() ? i : (i-s.top()-1));
        if(maxarea < area) {
            maxarea = area;
        }
    }
    return maxarea;
}

int main() {
    int n;
    cin >> n;
    long long int a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    cout << histogram(a, n) << endl;
    return 0;
}