class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int length = nums.size();
        stack<int> stk;
        vector<int> answers(length,-1);
        
        for(int i=2*length-1;i>=0;i--){
            while(!stk.empty() && stk.top() <= nums[i%length]){
                stk.pop();
            }
            if(i < length && !stk.empty()){
                answers[i] = stk.top();
            }
            stk.push(nums[i%length]);
        }
        return answers;
    }
};