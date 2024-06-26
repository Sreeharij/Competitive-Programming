class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if(n < m){
            return minDistance(word2,word1);
        }
        vector<int> prev(m+1,0);
        vector<int> curr(m+1,0);

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1] == word2[j-1]){
                    curr[j] = prev[j-1] + 1;
                }
                else{
                    curr[j] = max(prev[j],curr[j-1]);
                }
            }
            prev = curr;
        }
        int common = curr[m];
        return (n-common) + (m-common);
    }
};