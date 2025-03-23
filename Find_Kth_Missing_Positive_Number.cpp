#include <bits/stdc++.h>

using namespace std;

int findKthPositive(vector<int>& arr, int k) {
    int s = 0; 
    int e = arr.size();
    int mid = s + (e-s)/2;
    while(s<e){
        
        if(arr[mid] - mid - 1 < k){
            s = mid + 1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s+k;
}

int main() {
    int n, k;
    
    
    cout << "Enter number of elements in array: ";
    cin >> n;

    vector<int> arr(n);
    
    cout << "Enter the elements of the array (sorted in increasing order): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;


    int result = findKthPositive(arr, k);

    cout << "The " << k << "th missing positive number is: " << result << endl;

    return 0;
}

/*
Input:

Enter number of elements in array: 5
Enter the elements of the array (sorted in increasing order): 2 3 4 7 11
Enter the value of k: 5

Output:
The 5th missing positive number is: 9


*/
