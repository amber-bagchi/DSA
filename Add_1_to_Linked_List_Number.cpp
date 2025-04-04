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


Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}


Node* addOneUtil(Node* head) {
    Node* temp = head;
    int carry = 1;  

    while (temp) {
        int sum = temp->data + carry;
        temp->data = sum % 10;
        carry = sum / 10;
        
        if (carry == 0) break; 
        if (!temp->next && carry) { 
            temp->next = new Node(carry);
            carry = 0;
        }
        temp = temp->next;
    }
    return head;
}


Node* addOne(Node* head) {
    if (!head) return new Node(1);  

    head = reverse(head); 
    head = addOneUtil(head); 
    return reverse(head); 
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
    int n, data;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values to insert at tail: ";
    for (int i = 0; i < n; i++) {
        cin >> data;
        insertAtTail(head, data);
    }

    cout<<"Original Linked List:";
    print(head);

    head = addOne(head);

    cout<<"Added 1 Linked List: ";
    print(head);

    return 0;

}

/*

Enter number of nodes: 3
Enter 3 values to insert at tail: 4 5 9
Original Linked List: 4 5 9
Added 1 Linked List: 4 6 0


*/