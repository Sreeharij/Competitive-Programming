class Solution {
public:
    bool binary_search(vector<int>& nums,int target,int left,int right){
        int mid = (left + right)/2;
        if(left > right) return false;
        if(nums[mid] == target) return true;
        
        if((nums[left] == nums[mid]) && (nums[mid] == nums[right])){
            return binary_search(nums,target,left,mid-1) || binary_search(nums,target,mid+1,right);
        }
        if(nums[left] <= nums[mid]){
            if(nums[left] <= target && target <= nums[mid]){
                return binary_search(nums,target,left,mid-1);
            }
            else{
                return binary_search(nums,target,mid+1,right);
            }
        }
        else{
            if(nums[mid] <= target && target <= nums[right]){
                return binary_search(nums,target,mid+1,right);
            }
            else{
                return binary_search(nums,target,left,mid-1);
            }
        }
    }

    bool search(vector<int>& nums, int target) {
        return binary_search(nums,target,0,nums.size()-1);
    }
};