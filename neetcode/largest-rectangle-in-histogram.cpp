class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int length = heights.size();
        vector<int> previous_smaller(length,-1);
        vector<int> next_smaller(length,length);
        stack<int> stk;
        stk.push(0);
        for(int i=1;i<length;i++){
            while(!stk.empty() && heights[i] < heights[stk.top()]){
                next_smaller[stk.top()] = i;
                stk.pop();
            }
            if(!stk.empty()){
                previous_smaller[i] = stk.top();
            }
            stk.push(i);
        }
        int answer = INT_MIN;
        for(int i=0;i<length;i++){
            answer = max((next_smaller[i] - previous_smaller[i] - 1)*heights[i],answer);
        }
        return answer;
    }
};