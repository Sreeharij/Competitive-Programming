class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> answer(2*n);
        for(int i=0;i<2*n;i++){
            answer[i] = i%2==0 ? nums[i/2] : nums[i/2 + n];
        }
        return answer;
    }
};