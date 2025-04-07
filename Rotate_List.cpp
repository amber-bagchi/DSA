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

Node* findNthNode(Node* temp, int k){
    int cnt = 1;
    while(temp != NULL){
        if(cnt==k) return temp;
        cnt++;
        temp = temp->next;
    }
    return temp;
}

Node* rotateRight(Node* head, int k) {

    if(head == NULL || k==0) return head;

    int len = 1;
    Node* tail = head;

    while(tail->next !=NULL){
        len++;
        tail = tail->next;
    }

    if(k%len == 0) return head;

    k = k%len;

    tail->next = head;

    Node* newLastNode = findNthNode(head,len - k);

    head = newLastNode->next;
    newLastNode->next = NULL;

    return head;

}


void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    int n, k;

    cout << "Enter number of nodes in the list: ";
    cin >> n;

    cout << "Enter the elements of the list: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insertAtTail(head, val);
    }

    cout << "Enter number of rotations (k): ";
    cin >> k;

    head = rotateRight(head, k);

    cout << "List after rotating to the right by " << k << ": ";
    printList(head);

    return 0;
}

/*
Input:
Enter number of nodes in the list: 5
Enter the elements of the list: 1 2 3 4 5
Enter number of rotations (k): 2

Output:
List after rotating to the right by 2: 4 5 1 2 3
*/
