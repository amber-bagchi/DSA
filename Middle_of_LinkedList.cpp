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

Node* getMiddle(Node* head){

    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
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

    Node* middle = getMiddle(head);
    
    cout<<"Middle Linked List is:"<<endl;
    print(middle);

    return 0;
}

