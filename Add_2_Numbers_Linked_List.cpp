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

Node* addTwoNumbers(Node* l1, Node* l2) {

    Node* dummy = new Node(0);
    Node* current = dummy;
    int carry = 0;
    
    while (l1 || l2 || carry) {
        int val1 = (l1) ? l1->data : 0;
        int val2 = (l2) ? l2->data : 0;
        
        int total = val1 + val2 + carry;
        carry = total / 10;
        current->next = new Node(total % 10);
        current = current->next;
        
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    
    return dummy->next;
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
    Node* l1 = NULL;
    Node* l2 = NULL;
    
    int n, m, val;
    cout << "Enter number of digits in first number: ";
    cin >> n;
    cout << "Enter digits in reverse order: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertAtTail(l1, val);
    }
    
    cout << "Enter number of digits in second number: ";
    cin >> m;
    cout << "Enter digits in reverse order: ";
    for (int i = 0; i < m; i++) {
        cin >> val;
        insertAtTail(l2, val);
    }
    
    Node* result = addTwoNumbers(l1, l2);
    cout << "Resultant sum as linked list: ";
    print(result);
    
    return 0;
}

/*
Test Cases:
1.
Input:
3
2 4 3
3
5 6 4
Output:
7 0 8

2.
Input:
1
0
1
0
Output:
0

3.
Input:
7
9 9 9 9 9 9 9
4
9 9 9 9
Output:
8 9 9 9 0 0 0 1
*/
