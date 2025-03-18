#include <bits/stdc++.h>

using namespace std;
class Solution {
    public:
        int peakIndexInMountainArray(vector<int>& arr) {
    
            int s = 0;
            int e = arr.size()-1;
            int mid = s + (e-s)/2;
    
            while(s!=e){
                if(arr[mid]<arr[mid+1]){
                    s = mid + 1;
                }
                else{
                    e = mid;
                }
                mid = s + (e-s)/2;
            }
    
            return e;
            
        }
    };


    int main() {
        Solution sol;
        vector<int> nums = {5, 6, 7, 4, 3, 2, 1};
        
        int result = sol.peakIndexInMountainArray(nums);

        cout << "Peak Index: " << result << endl;
        
        return 0;
    }