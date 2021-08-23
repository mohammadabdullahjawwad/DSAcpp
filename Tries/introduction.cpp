#include <iostream>
#include <vector>
#include <unordered_map>
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

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

class node {
public:
    char data;
    unordered_map<char, node*> children;
    bool terminal;
    node(char d) {
        data = d;
        terminal = false;
    }
};

class Trie {

    node* root;
    int count; // Number of words in the trie

public:

    Trie() {
        root = new node('\0');
        count = 0;
    }

    void insert(char* w) {
        node* temp = root;
        for(int i=0; w[i]!='\0'; i++) {
            char ch = w[i];
            if(temp->children.count(ch)) {
                temp = temp->children[ch];
            }
            else {
                node* n = new node(ch);
                temp->children[ch] = n;
                temp = n;
            }
        }
        temp->terminal = true;
    }

    bool find(char* w) {
        node* temp = root;
        for(int i=0; w[i]!='\0'; i++) {
            char ch = w[i];
            if(temp->children.count(ch) == 0) {
                return false;
            }
            else {
                temp = temp->children[ch];
            }
        }
        return temp->terminal;
    }

};

int main() {
    OJ;
    Trie t;
    char words[][100] = {"a", "hello", "not", "news", "apple"};
    for(int i=0; i<5; i++) {
        t.insert(words[i]);
    }
    char w[10];
    cin >> w;
    if(t.find(w)) {
        cout << "Present" << endl;
    }
    else {
        cout << "Not Present" << endl;
    }
    return 0;
}