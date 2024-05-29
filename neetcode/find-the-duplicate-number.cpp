class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

        int second = nums[0];
        while(slow != second){
            second = nums[second];
            slow = nums[slow];
        }
        return second;
    }
};