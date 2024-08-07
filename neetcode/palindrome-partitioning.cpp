class Solution {
public:
    bool check_pallindrome(string& s,int left,int right){
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    void partition(vector<vector<bool>>& pallindromicity,vector<vector<string>>& answer,string& s,vector<string>& pattern,int start,int length){
        if(start == length){
            answer.push_back(pattern);
            return;
        }
        for(int i=start;i<length;i++){
            if(pallindromicity[start][i]){
                pattern.push_back(s.substr(start,i-start+1));
                partition(pallindromicity,answer,s,pattern,i+1,length);
                pattern.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> answer;
        int length = s.size();
        vector<string> pattern;
        vector<vector<bool>> pallindromicity(length,vector<bool>(length,false));
        for(int i=0;i<length;i++){
            for(int j=0;j<length;j++){
                if(check_pallindrome(s,i,j)){
                    pallindromicity[i][j] = true;
                }
            }
        }
        partition(pallindromicity,answer,s,pattern,0,length);
        return answer;
    }
};

//MOST EFFICIENT PALLINDROME PRECOMPUTATION
class Solution {
public:
    bool check_pallindrome(string& s,int left,int right){
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    void partition(vector<vector<bool>>& pallindromicity,vector<vector<string>>& answer,string& s,vector<string>& pattern,int start,int length){
        if(start == length){
            answer.push_back(pattern);
            return;
        }
        for(int i=start;i<length;i++){
            if(pallindromicity[start][i]){
                pattern.push_back(s.substr(start,i-start+1));
                partition(pallindromicity,answer,s,pattern,i+1,length);
                pattern.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> answer;
        int length = s.size();
        vector<string> pattern;
        vector<vector<bool>> pallindromicity(length,vector<bool>(length,false));
        for(int i=0;i<length;i++){
            pallindromicity[i][i] = true;
        }
        for(int i=0;i<length-1;i++){
            if(s[i] == s[i+1]){
                pallindromicity[i][i+1] = true;
            }
        }
        for(int len = 3;len <= length;len++){
            for(int i=0;i<=length-len;i++){
                int j = i + len - 1;
                if(s[i] == s[j] && pallindromicity[i+1][j-1]){
                    pallindromicity[i][j] = true;
                }
            }
        }
        partition(pallindromicity,answer,s,pattern,0,length);
        return answer;
    }
};