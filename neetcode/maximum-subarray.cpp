class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int absolute_max = nums[0];
        int current_sum = 0;
        int length = nums.size();
        for(int i=0;i<length;i++){
            current_sum += nums[i];
            absolute_max = max(absolute_max,current_sum);
            if(current_sum < 0){
                current_sum = 0;
            }
        }
        return absolute_max;
    }
};