class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int absolute_max = 0;
        int current_max = 0;
        bool flag = false;

        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1){
                flag = true;
                current_max++;
            }
            else{
                flag = false;
                absolute_max = current_max > absolute_max ? current_max : absolute_max;
                current_max = 0;
            }
        }
        absolute_max = current_max > absolute_max ? current_max : absolute_max;
        return absolute_max;
        
    }
};