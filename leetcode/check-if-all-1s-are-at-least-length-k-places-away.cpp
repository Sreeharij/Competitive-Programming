class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int space = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1){
                if(space > 0){
                    return false;
                }
                space = k;
            }
            else{
                space--;
            }
        }
        return true;
    }
};