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

Node* removeNthFromEnd(Node* head, int n) {

    Node* Dummy = new Node(-1);
    Dummy->next = head;

    Node* first = Dummy;
    Node* sec = Dummy;


    for(int i = 0; i<n; i++){
        sec = sec->next;
    }

    while(sec->next!=NULL){
        first = first->next;
        sec = sec->next;
    }

    Node* delnode = first->next;
    first->next = delnode->next;
    delete delnode;

    return Dummy->next;
    
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

    cout<<"Enter the position to delete: ";
    cin>>pos;
    head = removeNthFromEnd(head, pos);


    print(head);

    return 0;

}

/*

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]


Example 2:
Input: head = [1], n = 1
Output: []


Example 3:
Input: head = [1,2], n = 1
Output: [1]


*/