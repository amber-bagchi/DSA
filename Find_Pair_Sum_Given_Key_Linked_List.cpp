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

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    vector<pair<int, int>> ans;

    if (!head || !head->next)
        return ans;

    Node* left = head;
    Node* right = head;

    while (right->next)
        right = right->next;

    while (left != right && left->prev != right) {
        int sum = left->data + right->data;

        if (sum == target) {
            ans.emplace_back(left->data, right->data);
            left = left->next;
            right = right->prev;
        }
        else if (sum < target)
            left = left->next;
        else
            right = right->prev;
    }

    return ans;
}

void printPairs(vector<pair<int, int>> &pairs) {
    for (auto &p : pairs) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
}

int main() {
    Node *head = NULL;
    int n, val, target;

    cout << "Enter the number of elements in the doubly linked list: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertAtTail(head, val);
    }

    cout << "Enter the target sum: ";
    cin >> target;

    vector<pair<int, int>> result = findPairsWithGivenSum(head, target);

    if (result.empty()) {
        cout << "No pairs found" << endl;
    } else {
        cout << "Pairs with sum " << target << ": ";
        printPairs(result);
    }

    return 0;
}

/*
Test Case 1:
Input:
4
1 2 3 4
5
Output:
Pairs with sum 5: (1, 4) (2, 3)

Test Case 2:
Input:
5
1 2 3 4 5
10
Output:
No pairs found

Test Case 3:
Input:
6
1 1 2 3 4 5
6
Output:
Pairs with sum 6: (1, 5) (2, 4)
*/
