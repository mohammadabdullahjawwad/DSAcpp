#include <iostream>
#include <string>
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

    string s0;
    string s1("Hello");
    string s2 = "Hello World!";
    string s3(s2);
    string s4 = s3;

    char a[] = {'a', 'b', 'c', '\0'};
    string s5(a);

    cout << s0 << endl;
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << s5 << endl;

    cout << s0.empty() << endl;

    // Append
    s0.append("Yo my man");
    cout << s0 << endl;
    s0 += " and others too :p";
    cout << s0 << endl;

    // clear string
    cout << s0.length() << endl;
    s0.clear();
    cout << s0.length() << endl;

    // Compare two strings
    s0 = "Apple";
    s1 = "Mango";
    cout << s1.compare(s0) << endl;

    // Operator overloading for string comparison
    if(s0 < s1) {
        cout << s1 << endl;
    }
    else {
        cout << s0 << endl;
    }

    // Access particular index of a  string
    cout << s0[0] << endl;

    // Find substring
    string s = "I want to have apple juice";
    int idx = s.find("apple");
    cout << idx << endl;
    cout << s.substr(idx) << endl;

    // Remove a word from the string
    string word = "apple";
    int len = word.length();
    cout << s << endl;
    s.erase(idx, len+1);
    cout << s << endl;

    // Iterating over string
    // 1. Using iterator
    for(string::iterator it = s1.begin(); it != s1.end(); it++) {
        cout << (*it);
    }
    cout << endl;
    // 2. For each loop
    for(auto c:s1) {
        cout << c;
    }
    cout << endl;

    return 0;
}