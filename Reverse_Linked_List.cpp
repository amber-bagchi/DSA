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


void insertAtHead(Node *&head, int data) {
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}


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


Node* reverseIterative(Node* head) {
    Node *prev = NULL, *curr = head, *nex;
    while (curr != NULL) {
        nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    return prev; 
}


Node* reverseRecursive(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead; 
}

void print(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    int n, data;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values to insert at tail: ";
    for (int i = 0; i < n; i++) {
        cin >> data;
        insertAtTail(head, data);
    }

    cout << "Original Linked List: ";
    print(head);

    
    head = reverseIterative(head);
    cout << "Reversed (Iterative) Linked List: ";
    print(head);

    
    head = reverseRecursive(head);
    cout << "Reversed (Recursive) Linked List: ";
    print(head);

    return 0;
}
