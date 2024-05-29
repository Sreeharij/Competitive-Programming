class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int length = nums.size();
        int low=0,high=length-1,mid;

        int result = -1;
        while(low<=high){
            mid = (low+high)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                result = mid;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        if(result==-1){
            return 0;
        }
        else if(result==length-1){
            return length;
        }
        else{
            return result+1;
        }
    }
};