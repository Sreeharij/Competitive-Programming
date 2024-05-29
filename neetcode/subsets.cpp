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

/* THE BELOW IMPLEMENTATION IS ALSO CORRECT
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer_arr;
        vector<int> empty_vector;
        answer_arr.push_back(empty_vector);
        for(int i=1;i<=nums.size();i++){
            vector<int> individual_subset(i,0);
            get_subset(nums,answer_arr,individual_subset,i,0,0);
        }
        return answer_arr;
    }

    void get_subset(vector<int>& nums,vector<vector<int>>& answer_arr,vector<int>& individual_subset,int n,int current_level,int loop_start){
        if(n==1){
            for(int i=loop_start;i<nums.size();i++){
                individual_subset[current_level] = nums[i];
                answer_arr.push_back(individual_subset);
            }
        }
        else{
            for(int i=loop_start;i<nums.size()-n+1;i++){
                individual_subset[current_level] = nums[i];
                get_subset(nums,answer_arr,individual_subset,n-1,current_level+1,i+1);
            }
        }
    }
};

*/