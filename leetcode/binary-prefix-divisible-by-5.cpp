class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int length = nums.size();
        vector<bool> answer(length,false);
        int value = 0;
        for(int i=0;i<length;i++){
            value = ((value << 1) + nums[i])%5;
            answer[i] = value == 0 ? true : false;
        }

        return answer;
    }
};