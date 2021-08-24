#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void towerOfHanoi(int n, char source, char destination, char assist) {
    if(n == 0) {
        return;
    }
    towerOfHanoi(n - 1, source, assist, destination);
    cout << "Moving ring " << n << " from " << source << " to " << destination << endl;
    towerOfHanoi(n - 1, assist, destination, source);

}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}