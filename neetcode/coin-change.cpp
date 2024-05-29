class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<int> dp(amount+1,amount+1);
        dp[0] = 0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(coins[j] <= i){
                    dp[i] = min(1 + dp[i-coins[j]],dp[i]);
                }
                else{
                    break;
                }
            }
        }
        dp[amount] = dp[amount] == amount+1 ? -1 : dp[amount];
        return dp[amount];
    }
};
