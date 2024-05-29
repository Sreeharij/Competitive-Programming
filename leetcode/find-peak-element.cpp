class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 0,right = nums.size() - 1;
        int mid;
        if(left==right){
            return 0;
        }
        else if(nums[0] > nums[1]){
            return 0;
        }
        else if(nums[n-1] > nums[n-2]){
            return n-1;
        }
        while(left<=right){
            mid = (left + right)/2;
            if(mid == 0){
                left = mid + 1;
            }
            else if(mid == n-1){
                right = mid - 1;
            }
            else if(nums[mid] > nums[mid - 1]){
                if(nums[mid] > nums[mid + 1]){
                    break;
                }
                else{
                    left = mid + 1;
                }
            }
            else{
                right = mid - 1;
            }
        }
        return mid;   
    }
};