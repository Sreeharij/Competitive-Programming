class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> occurance_array;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == x)occurance_array.push_back(i);
        }
        vector<int> answer(queries.size(),-1);
        for(int i=0;i<queries.size();i++){
            if(queries[i] <= occurance_array.size()){
                answer[i] = occurance_array[queries[i]-1];
            }
        }
        return answer;
    }
};