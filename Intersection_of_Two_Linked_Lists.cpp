#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

    ListNode(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(ListNode *&head, int data)
{
    if (head == NULL)
    {
        head = new ListNode(data);
        return;
    }
    ListNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new ListNode(data);
}

int length(ListNode *head)
{
    int cnt = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (!headA || !headB)
        return NULL;

    int l1 = length(headA);
    int l2 = length(headB);
    int d = abs(l1 - l2);

    ListNode *ptr1 = (l1 >= l2) ? headA : headB;
    ListNode *ptr2 = (l1 >= l2) ? headB : headA;

    while (d--)
    {
        if (ptr1 == NULL)
            return NULL;
        ptr1 = ptr1->next;
    }

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
            return ptr1;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}

void printList(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    ListNode *headA = NULL, *headB = NULL;
    int n, m, x, intersectionIndex;

    // Input for first linked list
    cout << "Enter number of nodes for List A: ";
    cin >> n;
    cout << "Enter values for List A: ";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        insertAtTail(headA, x);
    }

    // Input for second linked list
    cout << "Enter number of nodes for List B: ";
    cin >> m;
    cout << "Enter values for List B: ";
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        insertAtTail(headB, x);
    }

    // Input intersection point
    cout << "Enter intersection index (-1 for no intersection): ";
    cin >> intersectionIndex;

    if (intersectionIndex != -1)
    {
        ListNode *tempA = headA;
        for (int i = 0; i < intersectionIndex && tempA != NULL; i++)
        {
            tempA = tempA->next;
        }

        if (tempA == NULL)
        {
            cout << "Invalid intersection index!" << endl;
            return 0;
        }

        ListNode *tempB = headB;
        while (tempB->next != NULL)
        {
            tempB = tempB->next;
        }
        tempB->next = tempA; // Connecting List B to intersection point in List A
    }

    // Print both lists
    cout << "List A: ";
    printList(headA);
    cout << "List B: ";
    printList(headB);


    ListNode *intersectNode = getIntersectionNode(headA, headB);
    if (intersectNode)
        cout << "Intersection at node with value: " << intersectNode->data << endl;
    else
        cout << "No intersection found" << endl;

    return 0;
}


/*

Enter number of nodes for List A: 5
Enter values for List A: 1 2 3 4 5
Enter number of nodes for List B: 3
Enter values for List B: 10 20 30
Enter intersection index (-1 for no intersection): 2
List A: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
List B: 10 -> 20 -> 30 -> 3 -> 4 -> 5 -> NULL
Intersection at node with value: 3

*/