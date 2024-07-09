class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int nums_length = nums.size();
        int queries_length = queries.size();
        vector<bool> answer(queries_length,false);
        vector<int> count_arr(nums_length);
        count_arr[0] = 1;
        int count = 1;
        for(int i=1;i<nums_length;i++){
            if(nums[i]%2 == nums[i-1]%2){
                count = 0;
            }
            count++;
            count_arr[i] = count;
        }
        for(int i=0;i<queries_length;i++){
            answer[i] = (queries[i][1] - queries[i][0] + 1 <= count_arr[queries[i][1]]);
        }

        return answer;
    }
};