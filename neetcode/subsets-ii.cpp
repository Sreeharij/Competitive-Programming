class Solution {
public:
    void generate_subsets(vector<vector<int>>& answer,vector<int>& nums,unordered_map<int,int>& freq_arr,int current_idx,int distinct_count,vector<int>& subset){
        if(current_idx == distinct_count){
            answer.push_back(subset);
            return;
        }
        generate_subsets(answer,nums,freq_arr,current_idx+1,distinct_count,subset);
        for(int i=0;i<freq_arr[nums[current_idx]];i++){
            subset.push_back(nums[current_idx]);
            generate_subsets(answer,nums,freq_arr,current_idx+1,distinct_count,subset);
        }
        for(int i=0;i<freq_arr[nums[current_idx]];i++){
            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> answer;
        int length = nums.size();
        unordered_map<int,int> freq_arr;
        int distinct_count = 0;
        vector<int> subset;
        for(int i=0;i<length;i++){
            if(freq_arr[nums[i]] == 0){
                distinct_count++;
            }
            freq_arr[nums[i]]++;
        }
        int idx=0;
        for(auto x:freq_arr){
            nums[idx++] = x.first;
        }
        generate_subsets(answer,nums,freq_arr,0,distinct_count,subset);
        return answer;
    }
};