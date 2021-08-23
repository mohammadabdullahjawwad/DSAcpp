#include <iostream>
#include <vector>
using namespace std;

template<typename T, typename U> // Converting into templste class in order to generalise the return data type
class Stack {
private: // We don't want the user to know what is inside the stack
    vector<T> v;
    vector<U> u;
public:
    void push(T data) {
        v.push_back(data);
    }
    bool empty() {
        return v.size() == 0;
    }
    void pop() {
        if(!empty()) {
            v.pop_back();
        }
    }
    T top() {
        return v[v.size()-1];
    }
};

int main() {
    Stack<int, long> s;
    for(int i=0; i<5; i++) {
        s.push(i*i);
    }
    while(!s.empty()) {
        cout << s.top() << "\n";
        s.pop();
    }
    cout << "\n";
    Stack<char, int> t;
    for(int i=65; i<75; i++) {
        t.push(i);
    }
    while(!t.empty()) {
        cout << t.top() << "\n";
        t.pop();
    }
    cout << "\n";
    return 0;
}