class Solution {
public:
    bool canJump(vector<int>& nums) {
        int energy = nums[0];
        for(int i=1;i<nums.size();i++){
            energy--;
            if(energy < 0) return false;
            if(nums[i] > energy){
                energy = nums[i];
            }
        }
        return true;
    }
};