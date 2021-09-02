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
        q1.push(x);
    }
    void pop() {
        if(q1.empty()) {
            return;
        }
        while(q1.size() > 1) {
            T f = q1.front();
            q1.pop();
            q2.push(f);
        }
        q1.pop();
        swap(q1, q2);
        // queue<T> temp = q1;
        // q1 = q2;
        // q2 = temp;
    }
    T top() {
        while(q1.size() > 1) {
            T f = q1.front();
            q1.pop();
            q2.push(f);
        }
        T ans = q1.front();
        q1.pop();
        q2.push(ans);
        swap(q1, q2);
        return ans;
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