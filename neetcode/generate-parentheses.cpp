class Solution {
public:
    void generate_strings(vector<string>& answer,string temp_string,int l_count,int r_count){
        if(r_count==0){
            answer.push_back(temp_string);
            return;
        }
        if(l_count == r_count){
            generate_strings(answer,temp_string + '(',l_count-1,r_count);
        }
        else{
            if(l_count){
                generate_strings(answer,temp_string + '(',l_count-1,r_count);
            }
            
            generate_strings(answer,temp_string + ')',l_count,r_count - 1);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> answer;    
        generate_strings(answer,"",n,n);
        return answer;
    }
};