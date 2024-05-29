class Solution {
public:
    int balancedStringSplit(string s) {
        int answer = 0;
        int l_count = 0,r_count = 0;
        for(int i=0;i<s.size();i++){
            if(l_count == r_count){
                answer += l_count!=0 ? 1 : 0;
                l_count = r_count = 0;
            }
            if(s[i] == 'R'){
                r_count++;
            }
            else{
                l_count++;
            }
        }
        if(l_count == r_count && l_count!=0){
            answer += 1;
        }
        return answer;
    }
};