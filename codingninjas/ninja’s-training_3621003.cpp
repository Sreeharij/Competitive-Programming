//BELOW IS TOP DOWN WITH MEMOIZATION
int func(vector<vector<int>> &points,int n,int last,vector<vector<int>>& dp){
    int max_val = 0;
    int current_branch = 0;
    if(dp[n][last] != -1){
        return dp[n][last];
    }
    if(n==0){
        for(int i=0;i<3;i++){
            if(i!=last){
                max_val = max_val > points[0][i] ? max_val : points[0][i];
            }
        }
    }
    else{
        for(int i=0;i<3;i++){
            if(i!=last){
                current_branch = points[n][i] + func(points,n-1,i,dp);
            }
            max_val = max_val > current_branch ? max_val : current_branch;
        }
    }
    dp[n][last] = max_val;
    return dp[n][last];
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int>(4,-1)); 
    int answer = func(points,n-1,3,dp);
    return answer;
}

//BELOW IS BOTTOM UP TABULATION
int ninjaTraining(int n, vector<vector<int>> &points)
{
    int dp[n][3];

    dp[0][0] = points[0][0];
    dp[0][1] = points[0][1];
    dp[0][2] = points[0][2];
    
    for(int i=1;i<n;i++){
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + points[i][0];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + points[i][1];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + points[i][2];
    }
    int max_val = dp[n-1][0] > dp[n-1][1] ? dp[n-1][0] : dp[n-1][1];
    max_val = max_val > dp[n-1][2] ? max_val : dp[n-1][2];

    return max_val;
}

//BELOW IS SPACE OPTIMISED APPROACH FOR USING COSNTANT SPACE
int ninjaTraining(int n, vector<vector<int>> &points)
{
    int dp[2][3];

    dp[0][0] = points[0][0];
    dp[0][1] = points[0][1];
    dp[0][2] = points[0][2];
    
    for(int i=1;i<n;i++){
        dp[1][0] = max(dp[0][1],dp[0][2]) + points[i][0];
        dp[1][1] = max(dp[0][0],dp[0][2]) + points[i][1];
        dp[1][2] = max(dp[0][0],dp[0][1]) + points[i][2];

        dp[0][0] = dp[1][0];
        dp[0][1] = dp[1][1];
        dp[0][2] = dp[1][2];
    }
    int max_val = dp[1][0] > dp[1][1] ? dp[1][0] : dp[1][1];
    max_val = max_val > dp[1][2] ? max_val : dp[1][2];

    return max_val;
}