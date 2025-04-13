#include <bits/stdc++.h>
using namespace std;

// Reuse your given global set
set<vector<int>> s;

// Your existing helper function
void findComb(vector<int>& arr, vector<int> &comb, vector<vector<int>> &ans,
              int index, int n, int target) {

    if(index == n || target < 0) {
        return;
    }

    if(target == 0) {
        if(s.find(comb) == s.end()) {
            ans.push_back(comb);
            s.insert(comb);
        }
        return;
    }

    // Include current element once
    comb.push_back(arr[index]);
    findComb(arr, comb, ans, index + 1, n, target - arr[index]);

    // Include current element again (can be picked unlimited times)
    findComb(arr, comb, ans, index, n, target - arr[index]);

    // Backtrack
    comb.pop_back();

    // Skip current element
    findComb(arr, comb, ans, index + 1, n, target);
}

// Your main combinationSum function
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    s.clear(); // Clear global set for fresh runs
    vector<int> comb;
    vector<vector<int>> ans;
    int index = 0;
    int n = candidates.size();
    findComb(candidates, comb, ans, index, n, target);
    return ans;
}

// ✅ Main function with user input
int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> candidates(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> candidates[i];
    }

    cout << "Enter target sum: ";
    cin >> target;

    vector<vector<int>> result = combinationSum(candidates, target);

    cout << "Combinations:\n";
    for(auto& comb : result) {
        for(int num : comb) {
            cout << num << " ";
        }
        cout << "\n";
    }

    return 0;
}



/*
Example Test Case 1:

Input:
Enter number of elements: 4
Enter elements: 2 3 6 7
Enter target sum: 7

Expected Output:
Combinations:
2 2 3
7

Explanation:
- 2 + 2 + 3 = 7
- 7 = 7
Only these two combinations sum to the target 7 using the given candidates.
*/
