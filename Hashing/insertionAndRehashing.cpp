#include<iostream>
#include<vector>
using namespace std;

#define vi vector <int>;
#define pii pair <int ,int>;
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

template<typename T>
class node {
public:
    string key;
    T value;
    node<T>* next;

    node(string key, T value) {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    // This will be a recursive destructor call to prevent memory leak
    ~node() {
        if(next != NULL) {
            delete next;
        }
    }
};

template<typename T>
class HashTable {

    node<T>** table; // Pointer to an array of pointers
    int currentSize;
    int tableSize;

    int hashFunction(string key) {
        int index = 0;
        int p = 1;
        for(int j=0; j<key.length(); j++) {
            // Doing % again and again to prevent overflow which may give negative indices and hence segmentation fault
            index = index + (key[j] * p) % tableSize;
            index %= tableSize;
            p = (p * 27) % tableSize;
        }
        return index;
    }

    void rehash() {
        node<T>** oldTable = table;
        int oldTableSize = tableSize;
        tableSize = 2 * tableSize + 3;
        table = new node<T>* [tableSize];
        for(int i=0; i<tableSize; i++) {
            table[i] = NULL;
        }
        currentSize = 0;
        //  Shift elements from old table to new table
        for(int i=0; i<oldTableSize; i++) {
            node<T>* temp = oldTable[i];
            while(temp != NULL) {
                // Elements of a row get inserted to new table
                insert(temp->key, temp->value);
                temp = temp->next;
            }
            // Delete the row from the old table
            if(oldTable[i] != NULL) {
                // Destructor deletes whole row (LL) recursively without iterating over it
                delete oldTable[i];
            }
        }
        // Delete table array since all rows are deleted
        delete [] oldTable; // It is a static pointer hence no memory leak after deletion
    }

public:

    HashTable(int tableSize=7) {
        this->tableSize = tableSize;
        table = new node<T>*[tableSize];
        currentSize = 0;
        for(int i=0; i<tableSize; i++) {
            table[i] = NULL;
        }
    }

    void insert(string key, T value) {
        // Create a LL
        int index = hashFunction(key);
        node<T>* n = new node<T>(key, value);
        // Insert at head of LL with id = index
        n->next = table[index];
        table[index] = n;
        currentSize++;
        // Rehash
        float loadFactor = currentSize / (1.0 * tableSize);
        // We keep the threshold as 0.7
        float threshold = 0.7;
        if(loadFactor > threshold) {
            rehash();
        }
    }

    void print() {
        for(int i=0; i<tableSize; i++) {
            cout << "Bucket " << i << " : ";
            node<T>* temp = table[i];
            while(temp != NULL) {
                cout << temp->key << "->";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    OJ;
    HashTable<int> menu;
    // menu.insert("Pasta", 100);
    menu.insert("Burger", 90);
    menu.insert("Noodles", 120);
    menu.insert("Fries", 75);
    menu.insert("Coke", 50);
    menu.insert("Pizza", 200);
    menu.print();
    return 0;
}