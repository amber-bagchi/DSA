#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->random = NULL;
    }
};

// Clone the list using hash map
Node* copyRandomList(Node* head) {
    if (head == NULL) return NULL;

    unordered_map<Node*, Node*> m;

    Node* newHead = new Node(head->val);
    Node* oldTemp = head->next;
    Node* newTemp = newHead;
    m[head] = newHead;

    while (oldTemp != NULL) {
        Node* copyNode = new Node(oldTemp->val);
        m[oldTemp] = copyNode;
        newTemp->next = copyNode;
        oldTemp = oldTemp->next;
        newTemp = newTemp->next;
    }

    oldTemp = head;
    newTemp = newHead;

    while (oldTemp != NULL) {
        newTemp->random = m[oldTemp->random];
        oldTemp = oldTemp->next;
        newTemp = newTemp->next;
    }

    return newHead;
}

// Function to print list with random pointers
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << "Node(" << temp->val << ")";
        if (temp->random)
            cout << " -> Random(" << temp->random->val << ")";
        else
            cout << " -> Random(NULL)";
        cout << endl;
        temp = temp->next;
    }
}

// Build list from user input
Node* buildList(int n, vector<int>& values, vector<int>& randomIndices) {
    if (n == 0) return NULL;

    vector<Node*> nodes(n);

    for (int i = 0; i < n; i++) {
        nodes[i] = new Node(values[i]);
        if (i > 0)
            nodes[i - 1]->next = nodes[i];
    }

    for (int i = 0; i < n; i++) {
        if (randomIndices[i] != -1)
            nodes[i]->random = nodes[randomIndices[i]];
    }

    return nodes[0];
}

// MAIN FUNCTION
int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> values(n);
    cout << "Enter " << n << " node values: ";
    for (int i = 0; i < n; i++)
        cin >> values[i];

    vector<int> randomIndices(n);
    cout << "Enter indices of random pointers (use -1 for NULL): ";
    for (int i = 0; i < n; i++)
        cin >> randomIndices[i];

    Node* original = buildList(n, values, randomIndices);

    cout << "\nOriginal List:\n";
    printList(original);

    Node* cloned = copyRandomList(original);

    cout << "\nCloned List:\n";
    printList(cloned);

    return 0;
}

/*

Sample Input:

Enter number of nodes: 4
Enter 4 node values: 10 20 30 40
Enter indices of random pointers (use -1 for NULL): 2 0 -1 1

Sample Output:

Original List:
Node(10) -> Random(30)
Node(20) -> Random(10)
Node(30) -> Random(NULL)
Node(40) -> Random(20)

Cloned List:
Node(10) -> Random(30)
Node(20) -> Random(10)
Node(30) -> Random(NULL)
Node(40) -> Random(20)




*/