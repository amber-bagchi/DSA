#include <iostream>
#include <vector>

using namespace std;

int cnt_lower(vector<int>& arr, int m, int k) {
    int s = 0;
    int e = m - 1;
    int ans = m;

    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] >= k) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}

int rowWithMax1s(vector<vector<int>> &arr) {
    int n = arr.size();
    int cnt_max = 0;
    int index = -1;

    for (int i = 0; i < n; i++) {
        int m = arr[i].size();
        int cnt_ones = m - cnt_lower(arr[i], m, 1);
        if (cnt_ones > cnt_max) {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}

int main() {
    int n, m;
    cout << "Enter number of rows (n): ";
    cin >> n;
    cout << "Enter number of columns (m): ";
    cin >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    cout << "Enter the binary matrix (only 0s and 1s):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int result = rowWithMax1s(arr);
    cout << "Row with maximum 1s: " << result << endl;

    return 0;
}

/*

Input:

Enter number of rows (n): 4
Enter number of columns (m): 4
Enter the binary matrix (only 0s and 1s):
0 0 0 1
0 1 1 1
1 1 1 1
0 0 0 0

Output:

Row with maximum 1s: 2


*/