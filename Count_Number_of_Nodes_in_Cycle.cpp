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

int countNodesinLoop(Node *head) {

    
    Node *slow = head, *fast = head;
    
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast) { 
            
            int count = 1;
            Node* temp = slow->next;
            while (temp != slow) {
                count++;
                temp = temp->next;
            }
            return count;
        }
    }
    

    return 0;
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

    int count = countNodesinLoop(head);
    if (count) {
        cout << "Number of nodes in the cycle are: " << count << endl;
    } else {
        cout << "No cycle detected." << endl;
    }



    return 0;
}