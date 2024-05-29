class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<int> dp(cols,0);
        dp[0] = obstacleGrid[0][0] == 0 ? 1 : 0;
        for(int j=1;j<cols;j++){
            if(obstacleGrid[0][j] == 1){
                dp[j] = 0;
            }
            else{
                dp[j] = dp[j-1];
            }
        }
        for(int i=1;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(obstacleGrid[i][j] == 1){
                    dp[j] = 0;
                }
                else{
                    if(j!=0){
                        dp[j] = dp[j] + dp[j-1];
                    }
                }
            }
        }
        int answer = dp[cols-1];
        return answer;
    }
};
