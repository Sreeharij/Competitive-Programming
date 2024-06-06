//o(m*n) time and O(m*n) space
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2){
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }
};


//Space optimised version. O(m*n)time and O(min(m,n)) space
class Solution {
public:
    void swap(string& a,string& b){
        string temp = a;
        a = b;
        b = temp;
    }

    int longestCommonSubsequence(string text1, string text2){
        if(text1.size() < text2.size()){
            swap(text1,text2);
        }
        int n = text1.size();
        int m = text2.size();

        vector<int> prev(m+1,0);
        vector<int> dp(m+1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1] == text2[j-1]){
                    dp[j] = prev[j-1] + 1;
                }
                else{
                    dp[j] = max(dp[j-1],prev[j]);
                }
            }
            prev = dp;
        }
        
        return dp[m];
    }
};