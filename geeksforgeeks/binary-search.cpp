class Solution {
public:
    int search(vector<int>& nums, int target) {
        int length = nums.size();
        int low=0,high=length-1,mid=0;

        bool flag = false;
        while(low<=high){
            mid = (low+high)/2;

            if(nums[mid]==target){
                flag = true;
                break;
            }
            else if(target > nums[mid]){
                low = mid+1;
            }
            else if(target < nums[mid]){
                high = mid-1;
            }
        }
        if(flag){
            return mid;
        }
        return -1;
    }
};