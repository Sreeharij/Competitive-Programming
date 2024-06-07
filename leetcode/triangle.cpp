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

//Add space optimised solution O(n) space
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int length = triangle.size();
        vector<int> prev(length,INT_MAX);
        vector<int> dp(length,INT_MAX);
        prev[0] = triangle[0][0];
        for(int i=0;i<length-1;i++){
            for(int j=0;j<=i;j++){
                dp[j] = min(dp[j],prev[j] + triangle[i+1][j]);
                dp[j+1] = min(dp[j+1],prev[j] + triangle[i+1][j+1]);
            }
            prev = dp;
            fill(dp.begin(),dp.end(),INT_MAX);
        }
        int answer = INT_MAX;
        for(int i=0;i<length;i++){
            answer = min(answer,prev[i]);
        }
        return answer;
    }
};