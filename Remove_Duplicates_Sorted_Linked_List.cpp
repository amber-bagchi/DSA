#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data) {
        this->data = data;
        this->prev = NULL;
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

    Node *newNode = new Node(data);
    temp->next = newNode;
    newNode->prev = temp;
}

void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *removeDuplicates(Node *head) {
    if (!head || !head->next) return head;

    Node* temp = head;
    
    while (temp && temp->next) {
        if (temp->data == temp->next->data) {
            Node* duplicate = temp->next;
            temp->next = duplicate->next;
            if (duplicate->next != NULL)
                duplicate->next->prev = temp;
            delete duplicate;
        } else {
            temp = temp->next;
        }
    }

    return head;
}

int main() {
    Node* head = NULL;
    int n;
    
    cout << "Enter the number of elements: ";
    cin >> n;
    
    cout << "Enter " << n << " elements (sorted order): ";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertAtTail(head, value);
    }

    cout << "Original List: ";
    printList(head);

    head = removeDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}

/*

Input:
Enter the number of elements: 5
Enter 5 elements (sorted order): 1 1 2 2 3

Output:
Original List: 1 1 2 2 3 
List after removing duplicates: 1 2 3 


*/