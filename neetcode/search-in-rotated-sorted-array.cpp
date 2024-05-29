class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0,right = nums.size() - 1,mid;
        int answer = -1;
        while(left<=right){
            mid = (left + right) / 2;

            if(nums[mid] == target){
                answer = mid;
                break;
            }
            else if(nums[left] <= nums[mid]){
                if((target <= nums[mid]) && (target >= nums[left])){
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            else{
                if((target <= nums[right]) && (target >= nums[mid])){
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }
        }
        return answer;
    }
};