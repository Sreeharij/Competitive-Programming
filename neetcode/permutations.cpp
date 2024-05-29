class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer_arr;
        int length = nums.size();
        int bitset_arr[length];
        vector<int> individual_permutation(length,0);
        for(int i=0;i<length;i++){
            bitset_arr[i] = 0;
        }
        get_permutation(nums,answer_arr,individual_permutation,bitset_arr,1,length);
        return answer_arr;
    }

    void get_permutation(vector<int>& nums,vector<vector<int>>& answer_arr,vector<int>& individual_permutation,int bitset_arr[],int level,int length){
        if(level==length){
            for(int i=0;i<length;i++){
                if(bitset_arr[i]==0){
                    individual_permutation[level-1] = nums[i];
                    answer_arr.push_back(individual_permutation);
                }
            }
        }
        else{
            for(int i=0;i<length;i++){
                if(bitset_arr[i]==0){
                    bitset_arr[i] = 1;
                    individual_permutation[level-1] = nums[i];
                    get_permutation(nums,answer_arr,individual_permutation,bitset_arr,level+1,length);
                    bitset_arr[i] = 0;
                }
            }
        }
    }
};