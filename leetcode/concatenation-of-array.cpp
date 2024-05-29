class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int length = nums.size();
        vector<int> answer(2*length);
        int idx;
        for(int i=0;i<2*length;i++){
            idx = i < length ? i : i - length;
            answer[i] = nums[idx]; 
        }
        return answer;
    }
};