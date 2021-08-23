#include <iostream>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

char words[][8] = {"nought", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void problem(int n) {
    if(n == 0) {
        return;
    }
    problem(n / 10);
    cout << words[n % 10] << " ";
}

int main() {
    OJ;
    FIO;
    int n;
    cin >> n;
    problem(n);
    cout << endl;
    return 0;
}
