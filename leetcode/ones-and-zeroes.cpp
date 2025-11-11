class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int answer = 0;
        int size = strs.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(auto st : strs){
            int zeroes = count(st.begin(),st.end(),'0');
            int ones = st.size() - zeroes;
            for(int i=m;i>= zeroes;i--){
                for(int j=n;j>=ones;j--){
                    dp[i][j] = max(dp[i-zeroes][j-ones] + 1, dp[i][j]);
                }
            }
        }
        return dp[m][n];
    }
};