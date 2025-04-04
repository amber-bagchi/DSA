#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        return;
    }

    Node *temp = new Node(data);
    head->prev = temp;
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&head, int data)
{
    if (head == NULL)
    {
        insertAtHead(head, data);
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    Node *newNode = new Node(data);
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteAllOccurOfX(struct Node **head, int x)
{
    Node *temp = *head;

    while (temp != NULL)
    {
        Node *next = temp->next;

        if (temp->data == x)
        {
            if (temp->prev)
                temp->prev->next = temp->next;
            else
                *head = temp->next;

            if (temp->next)
                temp->next->prev = temp->prev;

            delete temp;
        }

        temp = next;
    }
}

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    int n, val, x;

    cout << "Enter the number of elements in the doubly linked list: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        insertAtTail(head, val);
    }

    cout << "Enter value to delete all occurrences of: ";
    cin >> x;

    deleteAllOccurOfX(&head, x);

    cout << "Updated list: ";
    printList(head);

    return 0;
}

/*
Test Case 1:
Input:
Enter the number of elements in the doubly linked list: 7
Enter the elements: 1 2 3 4 3 5 3
Enter value to delete all occurrences of: 3
Output:
Updated list: 1 2 4 5

Test Case 2:
Input:
5
3 3 3 3 3
3
Output:

Test Case 3:
Input:
6
1 2 3 4 5 6
10
Output:
1 2 3 4 5 6
*/