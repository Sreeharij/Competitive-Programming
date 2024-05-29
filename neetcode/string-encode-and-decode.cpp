class Solution {
public:
    string encode(vector<string>& strs){
        string s = "";
        for(auto x: strs){
            string size = to_string(x.size());
            s = s + size + "#" + x;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> answer;
        int number = 0;
        int idx = 0;
        while(idx < s.size()){
            if(s[idx] == '#'){
                idx++;
                string word = "";
                while(number){
                    word += s[idx++];
                    number--;
                }
                answer.push_back(word);
            }
            else{
                number = number * 10 + (int)(s[idx++] - '0');
            }
        }
        return answer;
    }
};
