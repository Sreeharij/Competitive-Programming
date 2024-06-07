class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int length = matrix.size();
        vector<vector<int>> dp(length,vector<int>(length,INT_MAX));
        for(int i=0;i<length;i++)dp[0][i] = matrix[0][i];
        for(int i=0;i<length-1;i++){
            for(int j=0;j<length;j++){
                dp[i+1][j] = min(dp[i+1][j],dp[i][j] + matrix[i+1][j]);
                if(j-1 >= 0) dp[i+1][j-1] = min(dp[i+1][j-1],dp[i][j] + matrix[i+1][j-1]);
                if(j+1 < length) dp[i+1][j+1] = min(dp[i+1][j+1],dp[i][j] + matrix[i+1][j+1]);
            }
        }
        int answer = INT_MAX;
        for(int i=0;i<length;i++){
            answer = min(answer,dp[length-1][i]);
        }
        return answer;
    }
};