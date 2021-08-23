#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void towerOfHanoi(int n, char source, char destination, char assist, int& count) {
    if(n == 0) {
        return;
    }
    towerOfHanoi(n - 1, source, assist, destination, count);
    cout << "Move disc " << n << " from " << source << " to " << destination << endl;
    count++;
    towerOfHanoi(n - 1, assist, destination, source, count);
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    int count = 0;
    towerOfHanoi(n, 'A', 'C', 'B', count);
    cout << "Total moves : " << count << endl;
    return 0;
}