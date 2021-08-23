#include <iostream>
#include <algorithm>
using namespace std;

int indiaCurrency[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
int n = sizeof(indiaCurrency)/sizeof(int);
bool compare(int a, int b) {
    return a<=b;
}

void countNotes(int money) {
    // Base Case
    if(money == 0) {
        return;
    }
    // Recursive Case
    int largestIndex = lower_bound(indiaCurrency, indiaCurrency+n, money, compare) - indiaCurrency - 1;
    cout << indiaCurrency[largestIndex] << endl;
    countNotes(money - indiaCurrency[largestIndex]);
    return;
}

int main() {
    int money;
    cin >> money;
    countNotes(money);
    return 0;
}