class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> answer;
        int length = intervals.size();
        int left = 0;
        int right = length - 1;
        int idx = length;
        while(left <= right){
            int mid = (left + right)/2;
            if(intervals[mid][0] >= newInterval[0]){
                right = mid - 1;
                idx = mid;
            }
            else{
                left = mid + 1;
            }
        }
        idx = idx == -1 ? 0 : idx;
        intervals.insert(intervals.begin()+idx,newInterval);
        answer.emplace_back(intervals[0]);
        idx = 0;
        for(int i=1;i<length+1;i++){
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


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> answer;
        int length = intervals.size();
        for(int i=0;i<length;i++){
            if(intervals[i][1] < newInterval[0]){
                answer.emplace_back(intervals[i]);
            }
            else if(newInterval[1] < intervals[i][0]){
                answer.emplace_back(newInterval);
                for(int j=i;j<length;j++){
                    answer.emplace_back(intervals[j]);
                }
                return answer;
            }
            else {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        answer.emplace_back(newInterval);
        return answer;
    }
};