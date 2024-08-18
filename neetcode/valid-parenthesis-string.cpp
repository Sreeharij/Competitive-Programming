class Solution {
public:
    bool checkValidString(string s) {
        int counter = 0;
        for(char x: s){
            counter = (x == '(' || x == '*' ) ? counter + 1 : counter - 1;
            if(counter < 0)return false;
        }  
        counter = 0;
        for(int i = s.size()-1;i>=0;i--){
            char x = s[i];
            counter = (x == ')' || x == '*' ) ? counter + 1 : counter - 1;
            if(counter < 0)return false;
        }    
        return true;  
    }
};