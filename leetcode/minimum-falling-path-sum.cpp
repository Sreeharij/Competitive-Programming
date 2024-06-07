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


//O(n) space optimised sol 
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int length = matrix.size();
        int a,b,c;

        vector<int> dp(length,INT_MAX);
        vector<int> prev(length,INT_MAX);
        for(int i=0;i<length;i++)prev[i] = matrix[0][i];
        
        for(int i=1;i<length;i++){
            for(int j=0;j<length;j++){
                a = j-1 >= 0 ? matrix[i][j] + prev[j-1] : INT_MAX;
                b = matrix[i][j] + prev[j];
                c = j+1 < length ? matrix[i][j] + prev[j+1] : INT_MAX;
                dp[j] = min(a,min(b,c));
            }
            prev = dp;
        }
        int answer = INT_MAX;
        for(int i=0;i<length;i++){
            answer = min(answer,prev[i]);
        }
        return answer;
    }
};