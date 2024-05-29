class Solution {
public:
    int findMin(vector<int>& nums) {
        int lowest_value = 5000;
        int left = 0,right = nums.size()-1;
        int mid;
        while(left<=right){
            mid = (left + right) / 2;
            
            if(nums[left] <= nums[mid]){
                lowest_value = lowest_value < nums[left] ? lowest_value : nums[left]; 
                left = mid + 1;
            }
            else{
                lowest_value = lowest_value < nums[mid] ? lowest_value : nums[mid]; 
                right = mid - 1;
            }
        }
        return lowest_value;
    }
};