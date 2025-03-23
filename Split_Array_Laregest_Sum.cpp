#include <bits/stdc++.h>

using namespace std;

bool isPossible(vector<int>& nums, int n, int k, int mid){

    int count = 1;
    int sum = 0;

    for(int i = 0; i<n; i++){
        if(sum + nums[i] <= mid){
            sum += nums[i]; 
        }
        else{
            count++;
            if(count>k || nums[i]>mid){
                return false;
            }
            sum = 0;
            sum += nums[i];
        }
    }

    return true;

}


int splitArray(vector<int>& nums, int k) {

    int n = nums.size();
    int s = *max_element(nums.begin(), nums.end());
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum += nums[i];
    }

    

    int e = sum;
    int ans = -1;
    int mid = s + (e-s)/2;

    while(s<=e){
        if(isPossible(nums,n,k,mid)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}


int main() {
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter the number of subarrays (k): ";
    cin >> k;


    int result = splitArray(nums, k);
    
    cout << "The minimum largest subarray sum is: " << result << endl;

    return 0;
}

/*


Input:

Enter the number of elements in the array: 5
Enter 5 elements of the array: 7 2 5 10 8
Enter the number of subarrays (k): 2


Ouput:

The minimum largest subarray sum is: 18


*/