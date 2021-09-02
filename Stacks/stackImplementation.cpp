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

template<typename T, typename U> // Converting into template class in order to generalise the data type
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
        return v[v.size() - 1];
    }
};

int main() {
    OJ;
    FIO;
    Stack<int, long> s;
    for(int i=0; i<5; i++) {
        s.push(i*i);
    }
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
    Stack<char, int> t;
    for(int i=65; i<75; i++) {
        t.push(i);
    }
    while(!t.empty()) {
        cout << t.top() << " ";
        t.pop();
    }
    cout << "\n";
    return 0;
}