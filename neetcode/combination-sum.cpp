class Solution {
public:
    void backtrack(vector<vector<int>>& combinations,vector<int>& subset,vector<int>& candidates,int target,int start){
        if(target == 0){
            combinations.push_back(subset);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            if(candidates[i] > target)return;
            subset.push_back(candidates[i]);
            backtrack(combinations,subset,candidates,target-candidates[i],i);
            subset.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combinations;
        sort(candidates.begin(),candidates.end());
        vector<int> subset;
        backtrack(combinations,subset,candidates,target,0);
        return combinations;
    }
};