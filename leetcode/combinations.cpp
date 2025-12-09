class Solution {
public:
    void recurse(vector<vector<int>>& answer,vector<int> current_selection,int n,int k,int start){
        if(k == 0){
            answer.push_back(current_selection);
            return;
        }

        for(int i=start;i<=n;i++){
            current_selection.push_back(i);
            recurse(answer,current_selection,n,k-1,i+1);
            current_selection.pop_back();
        }

        return;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> answer;
        vector<int> current_selection;
        recurse(answer,current_selection,n, k, 1);

        return answer;
    }
};