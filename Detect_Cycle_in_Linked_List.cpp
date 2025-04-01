#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        return;
    }

    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&head, int data)
{
    if (head == NULL)
    {
        head = new Node(data);
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new Node(data);
}

void createCycle(Node *head, int pos) {
    if (pos == -1) return; 

    Node *temp = head, *cycleNode = NULL;
    int index = 1;

    while (temp->next != NULL) {
        if (index == pos) cycleNode = temp;
        temp = temp->next;
        index++;
    }
    if (cycleNode) temp->next = cycleNode; 
}

Node *hasCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return fast;
        }
    }

    return NULL;
}

Node *detectCycle(Node *head)
{

    Node *fast = hasCycle(head);
    Node *slow = head;

    if (fast != NULL)
    {
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    else
    {
        return NULL;
    }
}

void deleteCycle(Node *head)
{
    Node *fast = hasCycle(head);
    if (fast != NULL)
    {
        Node *slow = head;
        while (slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
    }
}

void print(Node *head)
{

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}



int main() {
    Node *head = NULL;
    int n, data, pos;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values to insert at tail: ";
    for (int i = 0; i < n; i++) {
        cin >> data;
        insertAtTail(head, data);
    }

    cout << "Enter the position to create a cycle (-1 for no cycle): ";
    cin >> pos;
    createCycle(head, pos);

    Node *cycleNode = detectCycle(head);
    if (cycleNode) {
        cout << "Cycle detected! It starts at node with value: " << cycleNode->data << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    deleteCycle(head);

    cout << "Linked List after deleting the cycle: ";
    print(head);

    return 0;
}