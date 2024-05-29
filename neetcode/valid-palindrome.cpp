class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0,end = s.size()-1;
        while(start<end){
            if(!character_within_range(s[start])){
                start++;
                continue;
            }
            if(!character_within_range(s[end])){
                end--; 
                continue;
            }
            bool condition;
            bool start_is_number = (s[start] >=48 && s[start]<=57);
            bool end_is_number = (s[end] >= 48 && s[end] <= 57);
            if(start_is_number){
                if(end_is_number){
                    if(s[start]==s[end]){
                        condition = true;
                    }
                    else{
                        condition = false;
                    }
                }
                else{
                    condition = false;
                }
            }
            else{
                if(end_is_number){
                    condition = false;
                }
                else{
                    if((s[start] == s[end]) || (s[start]-32 == s[end]) || (s[start]+32 == s[end])){
                        condition = true;
                    }
                    else{
                        condition = false;
                    }
                }
            }
            start++;
            end--;
            if (!condition){
                return false;
            }
        }
        return true;
    }

    bool character_within_range(char x){
        if ((x >= 97  && x<=122) || (x>=65 && x<=90) || (x>=48 && x<=57)){
            return true;
        }
        return false;
    }
};