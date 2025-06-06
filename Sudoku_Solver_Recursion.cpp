#include <iostream>
#include <vector>
using namespace std;

// Function declarations and definitions (reuse your previous logic)
bool iSafe(vector<vector<char>>& board, int row, int col, char dig) {
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == dig)
            return false;
    }

    for (int j = 0; j < 9; j++) {
        if (board[row][j] == dig) {
            return false;
        }
    }

    int srow = (row / 3) * 3;
    int scol = (col / 3) * 3;

    for (int i = srow; i <= srow + 2; i++) {
        for (int j = scol; j <= scol + 2; j++) {
            if (board[i][j] == dig) {
                return false;
            }
        }
    }

    return true;
}

bool Sudoku(vector<vector<char>>& board, int row, int col) {
    if (row == 9) {
        return true;
    }

    int nextrow = row, nextcol = col + 1;
    if (nextcol == 9) {
        nextrow = row + 1;
        nextcol = 0;
    }

    if (board[row][col] != '.') {
        return Sudoku(board, nextrow, nextcol);
    }

    for (char dig = '1'; dig <= '9'; dig++) {
        if (iSafe(board, row, col, dig)) {
            board[row][col] = dig;
            if (Sudoku(board, nextrow, nextcol)) {
                return true;
            }
            board[row][col] = '.';
        }
    }

    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    Sudoku(board, 0, 0);
}

int main() {
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    solveSudoku(board);

    cout << "Solved Sudoku Board:\n";
    for (const auto& row : board) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}
