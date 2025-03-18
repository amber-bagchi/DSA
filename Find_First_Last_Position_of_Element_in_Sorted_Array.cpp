#include<iostream>
#include<vector>


using namespace std;


class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            vector<int> ans(2, -1);
            ans[0] = findFirst(nums, target);
            ans[1] = findLast(nums, target);
            return ans;
        }
    
    private:
        
        int findFirst(vector<int>& nums, int target) {
            int s = 0, e = nums.size() - 1;
            int first = -1;
            
            while (s <= e) {
                int mid = s + (e - s) / 2;
                
                if (nums[mid] == target) {
                    first = mid; 
                    e = mid - 1;  
                } else if (nums[mid] > target) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            }
            
            return first;
        }
    
    
        int findLast(vector<int>& nums, int target) {
            int s = 0, e = nums.size() - 1;
            int last = -1;
            
            while (s <= e) {
                int mid = s + (e - s) / 2;
                
                if (nums[mid] == target) {
                    last = mid;  
                    s = mid + 1; 
                } else if (nums[mid] > target) {
                    e = mid - 1;
                } else {
                    s = mid + 1;
                }
            }
            
            return last;
        }
    
    };


    int main() {
        Solution sol;
        vector<int> nums = {5, 7, 7, 8, 8, 10};
        int target = 8;
        
        vector<int> result = sol.searchRange(nums, target);

        cout << "[" << result[0] << ", " << result[1] << "]" << endl;
        
        return 0;
    }