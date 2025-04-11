#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to generate all unique subsets
void solve(vector<int> nums, vector<int> output, vector<vector<int>> &ans, int i) {
    if (i == nums.size()) {
        ans.push_back(output);
        return;
    }

    // Include current element
    output.push_back(nums[i]);
    solve(nums, output, ans, i + 1);

    // Backtrack
    output.pop_back();

    // Skip duplicates
    int idx = i + 1;
    while (idx < nums.size() && nums[idx] == nums[idx - 1]) {
        idx++;
    }

    // Exclude current element and recurse
    solve(nums, output, ans, idx);
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());  
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
    cout << "Enter the elements (can include duplicates): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> result = subsetsWithDup(nums);

    cout << "\nUnique Subsets:\n";
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
4
1 2 2 3

Output:
Unique Subsets:
[ ]
[ 3 ]
[ 2 ]
[ 2 3 ]
[ 2 2 ]
[ 2 2 3 ]
[ 1 ]
[ 1 3 ]
[ 1 2 ]
[ 1 2 3 ]
[ 1 2 2 ]
[ 1 2 2 3 ]
*/
