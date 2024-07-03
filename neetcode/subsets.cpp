class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer_arr;
        vector<int> subset;
        int length = nums.size();
        get_subsets(nums,answer_arr,subset,length,1);

        return answer_arr;
    }

    void get_subsets(vector<int>& nums,vector<vector<int>>& answer_arr,vector<int>& subset,int length,int current_level){
        if(current_level==length){
            answer_arr.push_back(subset);
            subset.push_back(nums[current_level-1]);
            answer_arr.push_back(subset);
            subset.pop_back();
        }
        else{
            get_subsets(nums,answer_arr,subset,length,current_level+1);

            subset.push_back(nums[current_level-  1]);
            get_subsets(nums,answer_arr,subset,length,current_level+1);
            subset.pop_back();
        }      
    }
};

//ITERATIVE SOLUTION GIVEN BELOW
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        answer.push_back({});
        
        for(auto number: nums){
            int current_length = answer.size();
            for(int i=0;i<current_length;i++){
                vector<int> temp = answer[i];
                temp.push_back(number);
                answer.push_back(temp);
            }
        }
        return answer;
    }
};