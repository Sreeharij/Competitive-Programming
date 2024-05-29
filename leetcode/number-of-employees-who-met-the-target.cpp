class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int answer = 0;
        for(int i=0;i<hours.size();i++){
            answer += hours[i]>=target ? 1 : 0;
        }
        return answer;
    }
};