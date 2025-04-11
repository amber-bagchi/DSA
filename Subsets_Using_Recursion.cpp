#include <iostream>
#include <vector>
using namespace std;

// Recursive function to generate subsets
void solve(vector<int> nums, vector<int> output, vector<vector<int>> &ans, int i) {
    if (i == nums.size()) {
        ans.push_back(output);
        return;
    }

    // Exclude the current element
    solve(nums, output, ans, i + 1);

    // Include the current element
    output.push_back(nums[i]);
    solve(nums, output, ans, i + 1);
}

// Function to return all subsets
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> output;
    int i = 0;
    solve(nums, output, ans, i);
    return ans;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> result = subsets(nums);

    cout << "Subsets:\n";
    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}


/*
Input:
3
1 2 3

Expected Output:
Subsets:
[ ]
[ 3 ]
[ 2 ]
[ 2 3 ]
[ 1 ]
[ 1 3 ]
[ 1 2 ]
[ 1 2 3 ]
*/
