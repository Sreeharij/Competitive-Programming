class Solution {
public:
    bool isValid(string s) {
        stack<char> symbols;
        for(int i=0;i<s.size();i++){
            char letter = s[i];
            if(letter == '(' || letter == '[' || letter == '{'){
                symbols.push(letter);
            }
            else if(symbols.empty()){
                return false;
            }
            else if((symbols.top()=='(' && letter!=')') || (symbols.top()=='[' && letter!=']') || (symbols.top()=='{' && letter!='}')){
                    return false;
            }
            else{
                symbols.pop();
            }
        }
        if(!symbols.empty()){
            return false;
        }
        return true;
    }
};