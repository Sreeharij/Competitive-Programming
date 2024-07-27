class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals){
        vector<vector<int>> answer;
        sort(intervals.begin(),intervals.end());
        int length = intervals.size();
        answer.push_back(intervals[0]);
        int idx = 0;
        for(int i=1;i<length;i++){
            if(answer[idx][1] >= intervals[i][0]){
                answer[idx][1] = max(answer[idx][1],intervals[i][1]);
            }
            else{
                answer.emplace_back(intervals[i]);
                idx++;
            }   
        }
        return answer;
    }
};