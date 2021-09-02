#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define FIO \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL); \
    cout.tie(NULL);

#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

// head - Head pointer of the Linked List
// Return a boolean value indicating the presence of cycle
// If the cycle is present, modify the linked list to remove the cycle as well
bool floydCycleRemoval(Node *head)
{
    /* Code here */
}

/*
*
*
*   You do not need to refer or modify any code below this. 
*   Only modify the above function definition.
*	Any modications to code below could lead to a 'Wrong Answer' verdict despite above code being correct.
*	You do not even need to read or know about the code below.
*
*
*
*/

void buildCycleList(Node *&head)
{
    unordered_map<int, Node *> hash;
    int x;
    cin >> x;
    if (x == -1)
    {
        head = NULL;
        return;
    }
    head = new Node(x);
    hash[x] = head;
    Node *current = head;
    while (x != -1)
    {
        cin >> x;
        if (x == -1)
            break;
        if (hash.find(x) != hash.end())
        {
            current->next = hash[x];
            return;
        }
        Node *n = new Node(x);
        current->next = n;
        current = n;
        hash[x] = n;
    }
    current->next = NULL;
}

void printLinkedList(Node *head)
{
    unordered_set<int> s;
    while (head != NULL)
    {
        if (s.find(head->data) != s.end())
        {
            cout << "\nCycle detected at " << head->data;
            return;
        }
        cout << head->data << " ";
        s.insert(head->data);
        head = head->next;
    }
}

int main()
{
    OJ;
    FIO;
    Node *head = NULL;

    buildCycleList(head);

    bool cyclePresent = floydCycleRemoval(head);
    if (cyclePresent)
    {
        cout << "Cycle was present\n";
    }
    else
    {
        cout << "No cycle\n";
    }

    cout << "Linked List - ";
    printLinkedList(head);

    return 0;
}