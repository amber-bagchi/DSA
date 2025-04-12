#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        bool iSafe(vector<string> &board, int row, int col, int n) {
            // Check column
            for (int i = 0; i < row; i++) {
                if (board[i][col] == 'Q') return false;
            }
    
            // Check upper left diagonal
            for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
                if (board[i][j] == 'Q') return false;
            }
    
            // Check upper right diagonal
            for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
                if (board[i][j] == 'Q') return false;
            }
    
            return true;
        }
    
        void nQueen(vector<string> &board, vector<vector<string>> &ans, int row, int n) {
            if (row == n) {
                ans.push_back(board);
                return;
            }
    
            for (int col = 0; col < n; col++) {
                if (iSafe(board, row, col, n)) {
                    board[row][col] = 'Q';
                    nQueen(board, ans, row + 1, n);
                    board[row][col] = '.'; // backtrack
                }
            }
        }
    
        vector<vector<string>> solveNQueens(int n) {
            vector<string> board(n, string(n, '.'));
            vector<vector<string>> ans;
            nQueen(board, ans, 0, n);
            return ans;
        }
    };
    

    int main() {
        Solution sol;
        int n;
        cout << "Enter n (number of queens): ";
        cin >> n;
    
        vector<vector<string>> res = sol.solveNQueens(n);
        for (auto &board : res) {
            for (auto &row : board) {
                cout << row << endl;
            }
            cout << "----" << endl;
        }
    
        return 0;
    }
    