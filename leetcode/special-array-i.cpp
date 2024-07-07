class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int length = nums.size();
        for(int i=0;i<length-1;i++){
            if(nums[i]%2 == nums[i+1]%2)return false;
        }
        return true;
    }
};