class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0')return 0;
        int length = s.size();
        vector<int> dp(length+1,0);
        dp[length] = 1;
        dp[length-1] = s[length-1] == '0' ? 0 : 1;
        for(int i=length-2;i>=0;i--){
            if(s[i] == '0'){
                if(s[i+1] == '0') return 0;
                dp[i] = 0;
            }
            else{
                dp[i] = dp[i+1];
                if((int)(s[i]-'0')*10 + (int)(s[i+1]-'0')<=26){
                    dp[i] += dp[i+2];
                }
            }
        }
        return dp[0];
    }
};