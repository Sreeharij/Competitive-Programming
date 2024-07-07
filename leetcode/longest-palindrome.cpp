class Solution {
public:
    int longestPalindrome(string s) {
        int frequency[52] = {0};
        for(int i=0;i<s.size();i++){
            int idx;
            if(s[i]!=tolower(s[i])){  
                idx = tolower(s[i]) - 'a' + 26;
            }
            else{
                idx = s[i] - 'a';
            }
            frequency[idx]++;
        }
        bool odd = false;
        int answer = 0;
        for(int i=0;i<52;i++){
            if(frequency[i]%2 != 0){
                odd = true;
                answer += frequency[i] - 1;
            }   
            else{
                answer += frequency[i];
            }
        }   
        if(odd){
            answer++;
        }
        return answer;
    }
};