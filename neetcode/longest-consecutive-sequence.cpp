class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> values(nums.begin(),nums.end());
        int answer = 0;
        for(auto x:values){
            if(values.find(x-1) == values.end()){
                int length = 0;
                while(values.find(x+length) != values.end()){
                    length++;
                }
                answer = length > answer ? length : answer;
            }
        }
        return answer;
    }
};