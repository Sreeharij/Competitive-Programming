class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();

        int k=0;
        for(int i=1;i<length;i++){
            if(nums[i]!=nums[k]){
                nums[++k] = nums[i];
            }
        }
        return k+1;
    }
};