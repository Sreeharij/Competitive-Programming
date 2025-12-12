class Solution {
public:
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
    int firstMissingPositive(vector<int>& nums) {
        int length = nums.size();
        for(int i=0;i<length;i++){
            while(nums[i] > 0 && nums[i] <= length && nums[nums[i] - 1] != nums[i]) swap(nums[i],nums[nums[i] - 1]);
        }
        for(int i=0;i<length;i++)if(nums[i] != i+1)return i+1;

        return length+1;
    }
};