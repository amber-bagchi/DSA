#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int findMin(vector<int>& nums) {
            int s = 0;
            int e = nums.size()-1;
            int mid = s + (e-s)/2;
    
            while(s<e){
                if(nums[mid]>=nums[e]){
                    s = mid + 1;
                }
                else{
                    e = mid;
                }
    
                mid = s + (e-s)/2;
    
            }
            int ans = nums[s];
            return ans;
        }
    };


    int main() {
        Solution sol;
        vector<int> arr = {5, 6, 7, 4, 3, 2, 1};
        
        int result = sol.findMin(arr);

        cout << "Minimum Element: " << result << endl;
        
        return 0;
    }