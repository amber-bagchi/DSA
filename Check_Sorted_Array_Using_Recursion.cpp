#include <iostream>
#include <vector>
using namespace std;

// Recursive function to check if the array is sorted in non-decreasing order
int isSorted(int n, vector<int> a) {
    if (n == 0 || n == 1) return true;
    return a[n - 1] >= a[n - 2] && isSorted(n - 1, a);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (isSorted(n, a)) {
        cout << "The array is sorted in non-decreasing order." << endl;
    } else {
        cout << "The array is NOT sorted in non-decreasing order." << endl;
    }

    return 0;
}

/*
Example Test Case 1:
Input:
5
1 2 3 4 5
Output:
The array is sorted in non-decreasing order.

Example Test Case 2:
Input:
5
1 3 2 4 5
Output:
The array is NOT sorted in non-decreasing order.
*/
