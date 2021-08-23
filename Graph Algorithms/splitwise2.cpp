#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <climits>
#include <map>
#include <list>
#include <queue>
#include <set>
using namespace std;

#define vi vector<int>
#define pii pair<int ,int>
#define all(v) v.begin(), v.end()
#define pub push_back
#define pob pop_back
#define mp make_pair
#define ll long long int
#define MOD 1000000007
#define clr(val) memset(val,0,sizeof(val))

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

class personCompare {
public:
    bool operator()(pair<string, int> p1, pair<string, int> p2) {
        return p1.second < p2.second;
    }
};

int main() {
    OJ;
    FIO;
    int transactions, people;
    cin >> transactions >> people;
    string x, y;
    int amount;
    map<string, int> net;
    while(transactions--) {
        cin >> x >> y >> amount;
        // If key not present, we create it and initialize with 0
        if(!net.count(x)) {
            net[x] = 0;
        }
        if(!net.count(y)) {
            net[y] = 0;
        }
        net[x] -= amount;
        net[y] += amount;
    }
    multiset<pair<string, int>, personCompare> m;
    // Iterate over people, add those in the multiset with zero net
    for(auto p : net) {
        string person = p.first;
        int amt = p.second;
        if(net[person]) {
            m.insert(mp(person, amt));
        }
    }
    // Make settlements
    int cnt = 0;
    while(!m.empty()) {
        auto low = m.begin();
        auto high = prev(m.end());
        int debit = low->second;
        string debitPerson = low->first;
        int credit = high->second;
        string creditPerson = high->first;
        m.erase(low);
        m.erase(high);
        int settled = min(-debit, credit);
        debit += settled;
        credit -= settled;
        // Print the transaction
        cout << debitPerson << " will pay Rs. " << settled << " to " << creditPerson << endl;
        if(debit) {
            m.insert(mp(debitPerson, debit));
        }
        if(credit) {
            m.insert({creditPerson, credit});
        }
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}