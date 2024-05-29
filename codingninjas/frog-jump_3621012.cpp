#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    int diff1,diff2;
    int dp[n];
    memset(dp,0,sizeof(dp));
    dp[1] = heights[1] > heights[0] ? heights[1]-heights[0] : heights[0]-heights[1];
    for(int i=2;i<n;i++){
        diff1 = heights[i] > heights[i-1] ? heights[i]-heights[i-1] : heights[i-1]-heights[i];
        diff2 = heights[i] > heights[i-2] ? heights[i]-heights[i-2] : heights[i-2]-heights[i];
        if(dp[i-1]+diff1 < dp[i-2]+diff2){
            dp[i] = dp[i-1]+diff1;
        }
        else{
            dp[i] = dp[i-2]+diff2;
        }
    }
    return dp[n-1];
}