class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer;
        unordered_map<int,int> next_greater;
        stack<int> stk;
        
        for(auto number: nums2){
            while(!stk.empty() && number > stk.top()){
                next_greater[stk.top()] = number;
                stk.pop();
            }
            stk.push(number);
        }
        for(auto x: nums1){
            answer.push_back(next_greater.count(x) ? next_greater[x] : -1);
        }   

        return answer;
    }
};