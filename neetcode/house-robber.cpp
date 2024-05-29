//SPACE OPTIMISED SOLUTION
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int first = nums[0];
        int second = nums[0] > nums[1] ? nums[0] : nums[1];
        int current = second;
        for(int i=2;i<nums.size();i++){
            current = (first+nums[i]) > second ? (first+nums[i]): second;
            first = second;
            second = current;
        }
        return current;
    }
};