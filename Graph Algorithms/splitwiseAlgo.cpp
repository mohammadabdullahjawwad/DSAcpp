#include <iostream>
#include <set>
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
    int transactions, people;
    cin >> transactions >> people;
    // This array stores the net amount each person has to take in the end
    int net[1000000] = {0};
    int x, y, amount;
    while(transactions--) {
        cin >> x >> y >> amount;
        net[x] -= amount;
        net[y] += amount;
    }
    multiset<int> m;
    // Initialise and sort the list
    for(int i=0; i<people; i++) {
        if(net[i]) {
            m.insert(net[i]);
        }
    }
    int count = 0;
    // Pop out two people (L & R) and try to settle them
    while(!m.empty()) {
        auto left = m.begin();
        auto right = prev(m.end());
        int debit = *left;
        int credit = *right;
        // Remove them
        m.erase(left);
        m.erase(right);
        // Make a settlement
        int remaining = min(-debit, credit);
        count++;
        debit += remaining;
        credit -= remaining;
        if(debit) {
            m.insert(debit);
        }
        else if(credit) {
            m.insert(credit);
        }
    }
    cout << count << endl;
    return 0;
}