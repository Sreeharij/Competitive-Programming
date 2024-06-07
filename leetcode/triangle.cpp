class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int length = triangle.size();
        vector<vector<int>> dp(length,vector<int>(length,INT_MAX));
        dp[0][0] = triangle[0][0];

        for(int i=0;i<length-1;i++){
            for(int j=0;j<=i;j++){
                dp[i+1][j] = min(dp[i+1][j],dp[i][j] + triangle[i+1][j]);
                dp[i+1][j+1] = min(dp[i+1][j+1],dp[i][j] + triangle[i+1][j+1]);
            }
        }
        int answer = INT_MAX;
        for(int i=0;i<length;i++){
            answer = min(answer,dp[length-1][i]);
        }
        return answer;
    }
};