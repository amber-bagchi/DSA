#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *bottom;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->bottom = NULL;
    }
};

// Function to merge two bottom-linked lists
Node* merge(Node* a, Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    Node* result;

    if (a->data < b->data) {
        result = a;
        result->bottom = merge(a->bottom, b);
    } else {
        result = b;
        result->bottom = merge(a, b->bottom);
    }

    result->next = NULL;
    return result;
}

// Function to flatten the linked list
Node* flatten(Node* root) {
    if (root == NULL || root->next == NULL) return root;

    root->next = flatten(root->next);
    root = merge(root, root->next);

    return root;
}

// Function to insert a bottom linked list to a given node
void insertBottomList(Node* &head, vector<int> values) {
    if (values.empty()) return;

    head = new Node(values[0]);
    Node* curr = head;

    for (size_t i = 1; i < values.size(); i++) {
        curr->bottom = new Node(values[i]);
        curr = curr->bottom;
    }
}

// Function to insert a new top-level node at tail (like row)
void insertTopLevel(Node* &head, vector<int> bottomValues) {
    Node* newNode = nullptr;
    insertBottomList(newNode, bottomValues);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
}

// Function to print the flattened list
void printFlattenedList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->bottom;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    int n;
    cout << "Enter number of rows (top-level nodes): ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int m;
        cout << "Enter number of elements in row " << i + 1 << ": ";
        cin >> m;

        vector<int> values(m);
        cout << "Enter " << m << " sorted values for this row: ";
        for (int j = 0; j < m; j++) {
            cin >> values[j];
        }

        insertTopLevel(head, values);
    }

    Node* flatHead = flatten(head);

    cout << "\nFlattened Linked List:\n";
    printFlattenedList(flatHead);

    return 0;
}


/*
Input:
Enter number of rows (top-level nodes): 3
Enter number of elements in row 1: 3
Enter 3 sorted values for this row: 5 7 8
Enter number of elements in row 2: 2
Enter 2 sorted values for this row: 10 20
Enter number of elements in row 3: 4
Enter 4 sorted values for this row: 19 22 30 50

Output:
Flattened Linked List:
5 7 8 10 19 20 22 30 50 

*/