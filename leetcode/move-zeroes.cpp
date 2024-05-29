class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int length = nums.size();
        if(length==1){
            return;
        }
        int left = 0, right = 0;

        while(right<length){
            if(nums[right]!=0){
                nums[left++] = nums[right];
            }
            right++;
        }
        while(left<length){
            nums[left++]=0;
        }
    }
};