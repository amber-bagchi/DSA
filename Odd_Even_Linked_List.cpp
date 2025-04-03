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

Node* oddEvenList(Node* head) {

    if (!head || !head->next) {  
    return head;
    }

    Node* odd = head;
    Node* even = head->next;
    Node* evenStart = even;

    while(odd->next!=NULL && even->next!=NULL){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenStart;
    if(odd->next==NULL){
        even->next = NULL;
    }
    return head;
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


    head = oddEvenList(head);

    print(head);

    return 0;

}


/*

Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

*/