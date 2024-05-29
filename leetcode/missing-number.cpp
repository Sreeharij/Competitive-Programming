class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int length = nums.size();
        int result = length*(length+1)/2;
        for(int i=0;i<length;i++){
            result -= nums[i];
        }
        return result;
    }
};