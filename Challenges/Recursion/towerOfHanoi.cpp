#include <iostream>
using namespace std;

void towerOfHanoi(int n, char source, char destination, char assist) {
    if(n == 0) {
        return;
    }
    towerOfHanoi(n-1, source, assist, destination);
    cout << "Moving ring " << n << " from " << source << " to " << destination << endl;
    towerOfHanoi(n-1, assist, destination, source);

}

int main() {
    int n;
    cin >> n;
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}