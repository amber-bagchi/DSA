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


Node* segregate(Node* head) {
    if (head == NULL || head->next == NULL) return head; // Edge case: empty or single node

    Node* zero = new Node(-1), *zerotail = zero;
    Node* one = new Node(-1), *onetail = one;
    Node* two = new Node(-1), *twotail = two;

    Node* temp = head;

    // Step 1: Segregate nodes into three separate lists
    while (temp != NULL) {
        if (temp->data == 0) {
            zerotail->next = temp;
            zerotail = zerotail->next;
        } else if (temp->data == 1) {
            onetail->next = temp;
            onetail = onetail->next;
        } else {
            twotail->next = temp;
            twotail = twotail->next;
        }
        temp = temp->next;
    }

    // Step 2: Connect the three lists
    zerotail->next = (one->next != NULL) ? one->next : two->next;
    onetail->next = two->next;
    twotail->next = NULL; // Mark end of final list

    // Step 3: Update head to new sorted list
    head = zero->next;

    // Step 4: Delete dummy nodes to free memory
    delete zero;
    delete one;
    delete two;

    return head;
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    int n, data;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values to insert at head: ";
    for (int i = 0; i < n; i++) {
        cin >> data;
        insertAtTail(head, data);
    }

    cout << "Original Linked List: ";
    print(head);

    head = segregate(head);
    
    cout<<"Sorted Linked List is:"<<endl;
    print(head);

    return 0;
}

/*

Input: LinkedList: 1->2->2->1->2->0->2->2
Output: 0->1->1->2->2->2->2->2

*/

   