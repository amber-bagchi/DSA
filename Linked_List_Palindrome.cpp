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

Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* nex = NULL;

    while(curr!=NULL){
        nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    return prev;
}

Node* getMid(Node* head){
   
   Node* slow = head;
   Node* fast = head->next;

   while(fast!=NULL && fast->next!=NULL){

    slow = slow->next;
    fast = fast->next->next;

   }

    return slow;
}

bool isPalindrome(Node* head) {
    
    if(head==NULL || head->next==NULL){
        return true;
    }

    Node* mid = getMid(head);

    Node* temp = mid->next;
    mid->next = reverse(temp);

    Node* head1 = head;
    Node* head2 = mid->next;

    while(head2!=NULL){
        if(head1->data != head2->data){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    temp = mid->next;
    mid->next = reverse(temp);

    return true;

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
    Node* head = NULL;
    int n, data;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values to insert at tail: ";
    for (int i = 0; i < n; i++) {
        cin >> data;
        insertAtTail(head, data);
    }

    cout << "Linked List: ";
    print(head);

    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome.\n";
    } else {
        cout << "The linked list is NOT a palindrome.\n";
    }

    return 0;
}


/*
Input:
Enter the number of nodes: 5
Enter 5 values to insert at tail: 1 2 3 2 1

Output:
Linked List: 1 2 3 2 1
The linked list is a palindrome.
*/

/*
Input:
Enter the number of nodes: 4
Enter 4 values to insert at tail: 1 2 3 4

Output:
Linked List: 1 2 3 4
The linked list is NOT a palindrome.
*/
