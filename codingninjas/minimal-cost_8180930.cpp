//SPACE OPTIMISED TO USE DP ARRAY OF LENGTH K
//TWO WAYS OF STORING VALUES

//METHOD 1
int minimizeCost(int n, int k, vector<int> &height){
    int dp[k];
    memset(dp,0,sizeof(dp));
    int min_val;
    int absolute_max;

    for(int i=1;i<n;i++){
        min_val = INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j < 0){
                break;  
            }
            absolute_max = height[i] > height[i-j] ? height[i]-height[i-j] : height[i-j]-height[i];
            if(i>=k){
                min_val = (absolute_max + dp[k-j]) < min_val ? (absolute_max+dp[k-j]) : min_val;
            }
            else{
                min_val = (absolute_max + dp[i-j]) < min_val ? (absolute_max+dp[i-j]) : min_val;
            }        
        }
        if(i>=k){
            for(int i=0;i<k-1;i++){
                dp[i] = dp[i+1];
            }
            dp[k-1] = min_val;
        }
        else{
            dp[i] = min_val;
        }
    }
    
    return dp[k-1];
}

//METHOD 2

int minimizeCost(int n, int k, vector<int> &height){
    int dp[k];
    memset(dp,0,sizeof(dp));
    int min_val;
    int absolute_max;

    for(int i=1;i<n;i++){
        min_val = INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j < 0){
                break;  
            }
            absolute_max = height[i] > height[i-j] ? height[i]-height[i-j] : height[i-j]-height[i];
            min_val = (absolute_max + dp[(i-j)%k]) < min_val ? (absolute_max+dp[(i-j)%k]) : min_val; 
        }
        dp[i%k] = min_val;
    }
    
    return dp[(n-1)%k];
}