#include <bits/stdc++.h>
using namespace std;

void getper(vector<int> &nums, vector<vector<int>> &ans, int idx) {
    if (idx == nums.size()) {
        ans.push_back(nums);
        return;
    }

    for (int i = idx; i < nums.size(); i++) {
        swap(nums[idx], nums[i]);
        getper(nums, ans, idx + 1);
        swap(nums[idx], nums[i]); // backtrack
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    getper(nums, ans, 0);
    return ans;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> result = permute(nums);

    cout << "All permutations:\n";
    for (const auto &perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << "\n";
    }

    return 0;
}

/*
Test Case:
Input:
Enter number of elements: 3
Enter elements: 1 2 3

Output:
All permutations:
1 2 3 
1 3 2 
2 1 3 
2 3 1 
3 2 1 
3 1 2 
*/
