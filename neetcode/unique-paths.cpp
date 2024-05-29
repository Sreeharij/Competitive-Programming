//METHOD 1 USING O(m*n) TIME and O(m*n) SPACE 
class Solution {
public:
    int uniquePaths(int m, int n) {
        int matrix[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                matrix[i][j] = 0;
            }
        }
        matrix[0][0] = 1;
        for(int i=1;i<n;i++){
            matrix[0][i] = 1;
        }
        for(int i=1;i<m;i++){
            matrix[i][0] = 1;
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                matrix[i][j] += matrix[i][j-1] + matrix[i-1][j];
            }
        }
        return matrix[m-1][n-1];
    }
};


//METHOD 2 USING O(m*n) TIME AND O(n) SPACE - SPACE OPTIMISED SOLUTION
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[n];
        for(int i=0;i<n;i++){
            dp[i] = 1;
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[j] += dp[j-1];
            }
        }
    return dp[n-1];
    }
};