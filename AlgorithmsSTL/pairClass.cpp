#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void solve() {

    pair<int, char> p;
    p.first = 10;
    p.second = 'B';

    pair<int, char> p2(p);
    cout << p2.first << " " << p2.second << endl;

    pair<int, string> p3 = make_pair(100, "Audi");
    cout << p3.first << " " << p3.second << endl;

    int a, b;
    cin >> a >> b;
    pair<int, int> p4 = make_pair(a, b);
    cout << p4.first << " " << p4.second << endl;

    pair<int, int> p5(a, b);
    cout << p5.first << " " << p5.second << endl;

    pair<pair<int, int>, string> car; // It is generally advised to make a class instead of such a complex container
    car.second = "Audi";
    car.first.first = 10;
    car.first.second = 20;
    cout << car.first.first << " " << car.first.second << " " << car.second << endl;

}

int main() {
    OJ;
    FIO;
    solve();
    return 0;
}