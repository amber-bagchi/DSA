#include <bits/stdc++.h>
using namespace std;

// Function declarations
void combination2(vector<vector<int>> &res, vector<int> &combination,
                  vector<int> &candidates, int target, int index);

vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> combination;
    combination2(result, combination, candidates, target, 0);
    return result;
}

void combination2(vector<vector<int>> &res, vector<int> &combination,
                  vector<int> &candidates, int target, int index) {
    if (target == 0) {
        res.push_back(combination);
        return;
    }

    if (target < 0) return;

    for (int i = index; i < candidates.size(); i++) {
        if (i > index && candidates[i] == candidates[i - 1]) {
            continue;
        }
        combination.push_back(candidates[i]);
        combination2(res, combination, candidates, target - candidates[i], i + 1);
        combination.pop_back();
    }
}

int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> candidates(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> candidates[i];
    }

    cout << "Enter target: ";
    cin >> target;

    vector<vector<int>> results = combinationSum2(candidates, target);

    cout << "Combinations:\n";
    for (auto &comb : results) {
        for (int num : comb) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
Example Test Case:

Input:
Enter number of elements: 5
Enter elements: 2 5 2 1 2 
Enter target: 5

Expected Output:
Combinations:
1 2 2 
5 
*/
