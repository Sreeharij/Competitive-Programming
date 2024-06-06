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

    void partition(vector<vector<string>>& answer,string& s,vector<string>& pattern,int start,int length){
        if(start == length){
            answer.push_back(pattern);
            return;
        }
        for(int i=start;i<length;i++){
            if(check_pallindrome(s,start,i)){
                string word = s.substr(start,i-start+1);
                pattern.push_back(word);
                partition(answer,s,pattern,i+1,length);
                pattern.pop_back();
            }

        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> answer;
        int length = s.size();
        vector<string> pattern;
        partition(answer,s,pattern,0,length);
        return answer;
    }
};