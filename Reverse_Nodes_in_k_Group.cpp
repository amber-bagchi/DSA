#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node *&head, int data) {
    if (head == NULL) {
        head = new Node(data);
        return;
    }
    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new Node(data);
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* reverseKGroup(Node* head, int k) {
    Node* temp = head;
    int cnt = 0;

    // Check if there are at least k nodes to reverse
    while (cnt < k) {
        if (temp == NULL)
            return head;
        cnt++;
        temp = temp->next;
    }

    Node* PrevNode = reverseKGroup(temp, k);

    temp = head;
    cnt = 0;
    while (cnt < k) {
        Node* nextNode = temp->next;
        temp->next = PrevNode;
        PrevNode = temp;
        temp = nextNode;
        cnt++;
    }

    return PrevNode;
}

int main() {
    Node* head = NULL;
    int n, k;
    
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter the node values: ";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        insertAtTail(head, val);
    }

    cout << "Enter group size (k): ";
    cin >> k;

    head = reverseKGroup(head, k);

    cout << "List after reversing in groups of " << k << ": ";
    printList(head);

    return 0;
}


/*
Input:
Enter number of nodes: 6
Enter the node values: 1 2 3 4 5 6
Enter group size (k): 3

Output:
List after reversing in groups of 3: 3 2 1 6 5 4
*/
