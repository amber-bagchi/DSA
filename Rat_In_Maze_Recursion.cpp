#include <bits/stdc++.h>
using namespace std;

void findPath(vector<vector<int>> &arr, vector<string> &ans, string path, int row, int col, int n) {
    // Out of bounds or blocked or visited
    if (row < 0 || col < 0 || row >= n || col >= n || arr[row][col] == 0 || arr[row][col] == -1)
        return;

    // Destination reached
    if (row == n - 1 && col == n - 1) {
        ans.push_back(path);
        return;
    }

    arr[row][col] = -1; // mark visited

    // Move in all four directions
    findPath(arr, ans, path + "D", row + 1, col, n);
    findPath(arr, ans, path + "L", row, col - 1, n);
    findPath(arr, ans, path + "R", row, col + 1, n);
    findPath(arr, ans, path + "U", row - 1, col, n);

    arr[row][col] = 1; // backtrack
}

vector<string> searchMaze(vector<vector<int>> &arr, int n) {
    vector<string> ans;
    if (arr[0][0] == 0 || arr[n - 1][n - 1] == 0) return ans;
    findPath(arr, ans, "", 0, 0, n);
    sort(ans.begin(), ans.end()); // Sort result for lexicographic order
    return ans;
}


int main() {
    vector<vector<int>> maze = {
        {1, 1, 1, 0},
        {1, 1, 1, 0},
        {1, 0, 1, 1},
        {0, 0, 0, 1}
    };
    int n = 4;
    vector<string> result = searchMaze(maze, n);
    
    for (string path : result) {
        cout << path << " ";
    }
    return 0;
}
