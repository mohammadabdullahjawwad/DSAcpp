#include <iostream>
#include <queue>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

template<typename T>
class Stack {
    queue<T> q1, q2;
public:
    void push(T x) {
        q2.push(x);
        while(!q1.empty()) {
            T el = q1.front();
            q1.pop();
            q2.push(el);
        }
        swap(q1, q2);
    }
    void pop() {
        if(q1.empty()) {
            return;
        }
        q1.pop();
    }
    T top() {
        return q1.front();
    }
    int size() {
        return q1.size() + q2.size();
    }
    bool empty() {
        return size() == 0;
    }
};

int main() {
    OJ;
    FIO;
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}