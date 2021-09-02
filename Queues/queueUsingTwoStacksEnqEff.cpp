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

template<typename T>
class Queue {
    stack<T> s1, s2;
public:
    void push(T x) {
        s1.push(x);
    }
    void pop() {
        while(s1.size() > 1) {
            T el = s1.top();
            s1.pop();
            s2.push(el);
        }
        s1.pop();
        while(!s2.empty()) {
            T el = s2.top();
            s2.pop();
            s1.push(el);
        }
    }
    T front() {
        while(s1.size() > 1) {
            T el = s1.top();
            s1.pop();
            s2.push(el);
        }
        T f = s1.top();
        s1.pop();
        s2.push(f);
        while(!s2.empty()) {
            T el = s2.top();
            s2.pop();
            s1.push(el);
        }
        return f;
    }
    int size() {
        return s1.size() + s2.size();
    }
    bool empty() {
        return size() == 0;
    }
};

int main() {
    OJ;
    FIO;
    Queue<int> q;
    for (int i = 1; i < 5; i++) {
        q.push(i);
    }
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}