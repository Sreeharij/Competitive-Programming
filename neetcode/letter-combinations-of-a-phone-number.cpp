class Solution {
public:
    void combination(string &digits,int start,int end,unordered_map<int,string> &data,string temp_string,vector<string> &answer){
        if(start==end){
            answer.push_back(temp_string);
            return;
        }
        int current_digit = digits[start] - '0';
        for(auto letter: data[current_digit]){
            combination(digits,start+1,end,data,temp_string+letter,answer);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> answer;
        if(digits.size()==0){
            return answer;
        }
        unordered_map<int,string> data;
        data[2] = "abc";
        data[3] = "def";
        data[4] = "ghi";
        data[5] = "jkl";
        data[6] = "mno";
        data[7] = "pqrs";
        data[8] = "tuv";
        data[9] = "wxyz";
        answer.reserve(pow(4, digits.size()));
        combination(digits,0,digits.size(),data,"",answer);
        return answer;
    }
};