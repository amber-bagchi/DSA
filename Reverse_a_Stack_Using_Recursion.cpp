#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
  public:
    void insertAtBottom(stack<int> &St, int x) {
        if (St.empty()) {
            St.push(x);
            return;
        }
        int top = St.top();
        St.pop();
        insertAtBottom(St, x);
        St.push(top);
    }

    void Reverse(stack<int> &St) {
        if (St.empty()) {
            return;
        }
        int top = St.top();
        St.pop();
        Reverse(St);
        insertAtBottom(St, top);
    }
};

// Function to print the stack from top to bottom
void printStack(stack<int> St) {
    while (!St.empty()) {
        cout << St.top() << " ";
        St.pop();
    }
    cout << endl;
}

int main() {
    int n, val;
    stack<int> St;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements from **bottom to top** (first = bottom, last = top): ";
    vector<int> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    // Push elements to stack such that last input becomes the top
    for (int i = 0; i < n; i++) {
        St.push(input[i]);
    }

    cout << "\nOriginal stack (top to bottom): ";
    printStack(St);

    // Rebuild the stack to reverse
    for (int i = n - 1; i >= 0; i--) {
        St.push(input[i]);
    }

    Solution obj;
    obj.Reverse(St);

    cout << "Reversed stack (top to bottom): ";
    printStack(St);

    return 0;
}
