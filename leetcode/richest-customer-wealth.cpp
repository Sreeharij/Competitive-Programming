class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int absolute_max = 0;

        for(int i=0;i<accounts.size();i++){
            int current_wealth = 0;
            for(int j=0;j<accounts[0].size();j++){
                current_wealth += accounts[i][j];
            }
            absolute_max = absolute_max > current_wealth ? absolute_max : current_wealth;
        }
        return absolute_max;
    }
};