class Solution {
public:
    void backtrack(vector<int>& candidates,vector<int>& subset,vector<vector<int>>& combinations,int target,int start){
        if(target == 0){
            combinations.push_back(subset);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            if(i > start && candidates[i] == candidates[i-1])continue;
            if(candidates[i] <= target){
                subset.push_back(candidates[i]);
                backtrack(candidates,subset,combinations,target-candidates[i],i+1);
                subset.pop_back();
            }
            else{
                return;
            }

        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> combinations;
        sort(candidates.begin(),candidates.end());
        vector<int> subset;
        backtrack(candidates,subset,combinations,target,0);
        return combinations;
    }
};