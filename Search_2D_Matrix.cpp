#include <iostream>
#include <vector>

using namespace std;

bool Search(vector<int>& arr, int m, int k){
    int s = 0;
    int e = m - 1;
    bool ans = false;

    while(s<=e){
        int mid = s + (e-s)/2;
        if(arr[mid]==k) return true;
        if(arr[mid]>k) e = mid - 1;
        else s = mid + 1;
    }
    return ans;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    
    int n = matrix.size();
    int s = 0;
    int e = n - 1;
    int m = matrix[0].size();
    while(s<=e){
        int mid = s + (e-s)/2;

        if(target>=matrix[mid][0] && target<=matrix[mid][m-1]){
            return Search(matrix[mid],m,target);
        }
        else if(target>=matrix[mid][m-1]){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    
    return false;
}

int main() {
    int n, m, target;
    cout << "Enter number of rows (n): ";
    cin >> n;
    cout << "Enter number of columns (m): ";
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m));

    cout << "Enter the matrix elements row-wise (sorted in each row):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "Enter the target element to search: ";
    cin >> target;

    bool result = searchMatrix(matrix, target);
    if (result)
        cout << "Target found in matrix." << endl;
    else
        cout << "Target not found in matrix." << endl;

    return 0;
}


/*

Input:
Enter number of rows (n): 3
Enter number of columns (m): 4
Enter the matrix elements row-wise (sorted in each row):
1 3 5 7
10 11 16 20
23 30 34 60
Enter the target element to search: 16

Output:
Target found in matrix.


*/