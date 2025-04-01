#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int data){

    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        return;
    }

    Node* temp = new Node(data);
    head->prev = temp;
    temp->next = head;
    head = temp;

}

void insertAtTail(Node* &head, int data){

    if(head==NULL){
        insertAtHead(head, data);
        return;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }

    Node *newNode = new Node(data);
    temp->next = newNode;
    newNode->prev = temp;

}

void insertAtPosition(Node* &head, int pos, int data){
    
    if(head==NULL){
        insertAtHead(head, data);
        return;
    }
    Node* temp = head;
    int count = 1;
    while(temp->next!=NULL && count<pos-1){
        temp = temp->next;
        count++;
    }

    if(temp->next==NULL){
        insertAtTail(head, data);
        return;
    }

    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteAtHead(Node* &head){

    if(head==NULL){
        cout<<"Linked List is empty"<<endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;

}

void deleteAtTail(Node* &head){
    if(head==NULL){
        cout<<"Linked List is empty"<<endl;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->prev->next = NULL;
    delete temp;


}

void deleteAtPosition(Node* &head, int pos){
    if(head==NULL){
        cout<<"Linked List is empty"<<endl;
        return;
    }

    Node *temp = head;
    int cnt = 1;
    while(temp->next != NULL && cnt<pos - 1){
        temp = temp->next;
        cnt++;
    }

    if(temp->next==NULL){
        cout<<"Position out of index"<<endl;
        return;
    }

    Node* deleteNode = temp->next;
    deleteNode->next->prev = temp;
    temp->next = deleteNode->next;
    delete deleteNode;


}

Node* reverseDLL(Node* head) {
    // Your code here
    Node* rev = NULL;
    
    Node* temp = head;
    
    while(temp!=NULL){
        insertAtHead(rev, temp->data);
        temp=temp->next;
    }
    
    
    return rev;
}

void print(Node* head){

    Node* temp = head;

    cout<<"Linked List is: "<<endl;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;

}

int main() {
    Node* head = NULL;
    int choice, data, pos;

    do {
        cout << "\n--- Doubly Linked List Operations Menu ---\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert at a Position\n";
        cout << "4. Delete from Head\n";
        cout << "5. Delete from Tail\n";
        cout << "6. Delete from a Position\n";
        cout << "7. Print Linked List\n";
        cout << "8. Reverse Linked List\n";  // Added Reverse Option
        cout << "9. Exit\n";
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

            case 8: // Reverse Doubly Linked List
                head = reverseDLL(head);
                cout << "Doubly Linked List reversed successfully!" << endl;
                break;

            case 9:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }
    } while (choice != 9);

    return 0;
}




/*
int main(){

    Node* head = NULL;



    insertAtHead(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);
    insertAtPosition(head, 3, 25);
    print(head);

    deleteAtHead(head);
    deleteAtTail(head);
    deleteAtPosition(head, 3);
    print(head);

    return 0;
}

*/