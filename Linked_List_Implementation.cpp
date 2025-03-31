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

    Node *temp = new Node(data);

    if (head == NULL)
    {
        head = temp;
        return;
    }

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

    temp->next = new Node(data);
}

void insertAtPosition(Node* &head, int pos, int data) {
    if (pos <= 0) {
        cout << "Invalid position!" << endl;
        return;
    }

    if (pos == 1 || head == NULL) {  
        insertAtHead(head, data);
        return;
    }

    Node* temp = head;
    int count = 1;

   
    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    
    if (temp == NULL) {
        cout << "Position out of range!" << endl;
        return;
    }

    
    Node* toinsert = new Node(data);
    toinsert->next = temp->next;
    temp->next = toinsert;
}


void deleteAtHead(Node *&head){

    if(head==NULL){
        cout<<"Linked List is empty"<<endl;
        return;
    }

    Node *temp = head;
    head = head->next;
    delete temp;
}

void deleteAtTail(Node *&head){
    if(head==NULL){
        cout<<"Linked List is empty"<<endl;
        return;
    }

    Node* temp = head;

    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    
    Node* deleteNode = temp->next;
    temp->next = NULL;
    delete deleteNode;

}

void deleteAtPosition(Node* &head, int pos) {
    if (head == NULL) {
        cout << "Linked List is empty" << endl;
        return;
    }

    if (pos <= 0) {
        cout << "Invalid position!" << endl;
        return;
    }

    if (pos == 1) { 
        deleteAtHead(head);
        return;
    }

    Node *temp = head;
    int count = 1;

    
    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    
    if (temp == NULL || temp->next == NULL) {
        cout << "Position out of range!" << endl;
        return;
    }

    Node *deleteNode = temp->next;  
    temp->next = temp->next->next;  
    delete deleteNode;  
}


void print(Node *&head)
{

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main() {
    Node *head = NULL;
    int choice, data, pos;

    do {
        cout << "\n--- Linked List Operations Menu ---\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert at a Position\n";
        cout << "4. Delete from Head\n";
        cout << "5. Delete from Tail\n";
        cout << "6. Delete from a Position\n";
        cout << "7. Print Linked List\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert at head: ";
                cin >> data;
                insertAtHead(head, data);
                break;

            case 2:
                cout << "Enter data to insert at tail: ";
                cin >> data;
                insertAtTail(head, data);
                break;

            case 3:
                cout << "Enter position: ";
                cin >> pos;
                cout << "Enter data to insert: ";
                cin >> data;
                insertAtPosition(head, pos, data);
                break;

            case 4:
                deleteAtHead(head);
                break;

            case 5:
                deleteAtTail(head);
                break;

            case 6:
                cout << "Enter position to delete: ";
                cin >> pos;
                deleteAtPosition(head, pos);
                break;

            case 7:
                print(head);
                break;

            case 8:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }
    } while (choice != 8);

    return 0;
}
