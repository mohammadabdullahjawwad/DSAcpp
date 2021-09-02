#include <iostream>
#include <queue>
#include <unordered_map>
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
    queue<char> qu;
    unordered_map<char, int> mp;
    char ch;
    cin >> ch;
    while (ch != '.') {
        qu.push(ch);
        mp[ch]++;
        while(!qu.empty()) {
            if(mp[qu.front()] > 1) {
                qu.pop();
            }
            else {
                cout << qu.front() << endl;
                break;
            }
        }
        if(qu.empty()) {
            cout << -1 << endl;
        }
        cin >> ch;
    }
    return 0;
}