class Solution {
public:
    void binary_search_func(vector<int>& nums,int low, int high, int target,vector<int>& answer){
        if(low > high){
            return;
        }
        int mid = (low + high)/2;

        if(target > nums[mid]){
            binary_search_func(nums,mid+1,high,target,answer);
        }
        else if(target < nums[mid]){
            binary_search_func(nums,low,mid-1,target,answer);
        }
        else{
            if(answer[0] == -1){
                answer[0] = answer[1] = mid;
            }
            else{
                if(mid < answer[0]){
                    answer[0] = mid;
                }
                else if(mid > answer[1]){
                    answer[1] = mid;
                }
            }
            binary_search_func(nums,low,mid-1,target,answer);
            binary_search_func(nums,mid+1,high,target,answer);
        }
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int length = nums.size();
        int low = 0,high = length-1,mid;
        vector<int> answer(2,-1);
        binary_search_func(nums,low,high,target,answer);
        return answer;
        
    }
};
