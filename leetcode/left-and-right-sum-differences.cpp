class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int length = nums.size();
        int left[length];
        int right[length];
        left[0] = right[length-1] = 0;
        for(int i=1;i<length;i++){
            left[i] = nums[i-1] + left[i-1];
        }
        for(int i=length-2;i>=0;i--){
            right[i] = right[i+1] + nums[i+1];
        }
        vector<int> answer(length,0);
        for(int i=0;i<length;i++){
            answer[i] = (left[i]-right[i]) < 0 ? (right[i]-left[i]) : (left[i]-right[i]);
        }
        return answer;
    }
};