#include <bits/stdc++.h>
using namespace std;


    
    int findMaxIndex(vector<int>& row) {
        return max_element(row.begin(), row.end()) - row.begin();
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int low = 0, high = mat.size() - 1;
        int m = mat[0].size();

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int maxColIndex = findMaxIndex(mat[mid]);

            int up = (mid > 0) ? mat[mid - 1][maxColIndex] : -1;
            int down = (mid < mat.size() - 1) ? mat[mid + 1][maxColIndex] : -1;

            
            if (mat[mid][maxColIndex] > up && mat[mid][maxColIndex] > down) {
                return {mid, maxColIndex};
            }
            
            else if (mat[mid][maxColIndex] < up) {
                high = mid - 1;
            }
            
            else {
                low = mid + 1;
            }
        }

        return {-1, -1}; 
    }



int main() {

        
        int n, m;
        cout << "Enter number of rows and columns: ";
        cin >> n >> m;
    
        vector<vector<int>> mat(n, vector<int>(m));
        cout << "Enter the matrix elements row-wise:\n";
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
    
        vector<int> peak = findPeakGrid(mat);
        cout << "Peak found at: (" << peak[0] << ", " << peak[1] << ")" << endl;
    
        return 0;
    }
    
    /*
    Input:
    6 6
    1  2  3  6  5  4
    14 13 9  12 11 10
    7  8  16 15 19 18
    20 22 23 24 25 21
    30 29 28 27 26 31
    40 41 42 43 44 45
    
    Expected Output:
    Peak found at: (5, 5) 
    */
