#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
    
        int findpivot(vector<int>& nums){
    
            int s = 0;
            int e = nums.size()-1;
            int mid = s + (e-s)/2;
    
            while(s<e){
                if(nums[mid]>nums[e]){
                    s = mid + 1;
                }
                else{
                    e = mid;
                }
    
                mid = s + (e-s)/2;
            }
    
            return s;
    
        }
    
        int search(vector<int>& nums, int target) {
            if (nums.empty()) return -1;  
    
            int pivot = findpivot(nums);
    
            int s, e;
            if (target >= nums[pivot] && target <= nums[nums.size() - 1]) {
                s = pivot;
                e = nums.size() - 1;
            } else {
                s = 0;
                e = pivot - 1;
            }
    
            while (s <= e) {
                int mid = s + (e - s) / 2;
                if (nums[mid] == target) return mid;
                else if (nums[mid] < target) s = mid + 1;
                else e = mid - 1;
            }
    
            return -1;
        }
    };

    int main() {
        Solution sol;
        vector<int> nums = {5, 7, 8, 9, 10, 0, 1};
        int target = 8;
        
        int result = sol.search(nums, target);

        cout <<"Index : "<<result<< endl;
        
        return 0;
    }