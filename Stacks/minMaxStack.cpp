#include <iostream>
#include <vector>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

template <typename T>
class MinMaxStack {
    vector<T> a;
    vector<T> minStack;
    vector<T> maxStack;
public:
    void push(T x) {
        T currMin = x;
        T currMax = x;
        if(minStack.size()) {
            currMin = min(minStack[minStack.size() - 1], x);
            currMax = max(maxStack[maxStack.size() - 1], x);
        }
        a.push_back(x);
        minStack.push_back(currMin);
        maxStack.push_back(currMax);
    }
    void pop() {
        a.pop_back();
        minStack.pop_back();
        maxStack.pop_back();
    }
    T top() {
        return a[a.size() - 1];
    }
    bool empty() {
        return a.size() == 0;
    }
    T getMin() {
        return minStack[minStack.size() - 1];
    }
    T getMax() {
        return maxStack[maxStack.size() - 1];
    }
    void print() {
        for(T x: a) {
            cout << x << " ";
        }
        cout << endl;
        for(T x: minStack) {
            cout << x << " ";
        }
        cout << endl;
        for(T x: maxStack) {
            cout << x << " ";
        }
        cout << endl;
        cout << endl;
    }
};

int main() {
    OJ;
    FIO;
    MinMaxStack<int> s;

    s.push(1);
    s.push(5);
    s.push(3);
    s.push(8);

    s.print();

    cout << s.getMax() << endl;
    s.pop();
    cout << s.getMin() << endl;
    cout << s.getMax() << endl;

    s.pop();
    s.pop();
    cout << s.top() << endl;
    cout << s.getMax() << endl;

    return 0;
}