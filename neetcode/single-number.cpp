class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int length = nums.size();
        int counter = 0;
        
        for(int i=0;i<length;i++){
            counter = counter ^ nums[i];
        }
        return counter;
    }
};