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


//O(n) time and O(1) space
class Solution {
public:
    int numDecodings(string s) {
        int length = s.size();
        if(s[0] == '0')return 0;

        int first = 1;
        int second = 1;
        int current;
        for(int i=2;i<=length;i++){
            current = 0;
    
            if(stoi(s.substr(i-1,1)) <= 9 && stoi(s.substr(i-1,1)) > 0)current += second;
            if(stoi(s.substr(i-2,2)) >= 10 && stoi(s.substr(i-2,2)) <= 26)current += first;
            first = second;
            second = current;
        }
        

        return second;
    }
};