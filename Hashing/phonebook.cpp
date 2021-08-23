#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define vi vector <int>
#define pii pair <int ,int>
#define all(v) v.begin(),v.end()
#define pub push_back
#define pob pop_back
#define mp make_pair
#define ll long long int
#define MOD 1000000007
#define clr(val) memset(val,0,sizeof(val))

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main() {
    OJ;
    unordered_map<string, vector<string>> phonebook;
    phonebook["Genius"].pub("9755125125");
    phonebook["Genius"].pub("9865435468");
    phonebook["Genius"].pub("8495758565");
    phonebook["Genius"].pub("9734937457");
    phonebook["Jawwad"].pub("8027555566");
    phonebook["Jawwad"].pub("7656464922");
    phonebook["Jawwad"].pub("6388151348");
    // Print all contacts
    for(auto p : phonebook) {
        cout << p.first << " : ";
        for(auto v : p.second) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;
    // Search a contact by name
    string name;
    cin >> name;
    if(phonebook.count(name)) {
        for(auto n : phonebook[name]) {
            cout << n << " ";
        }
        cout << endl;
    }
    else {
        cout << name << " not found!" << endl;
    }
    return 0;
}