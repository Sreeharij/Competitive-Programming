class Solution {
public:
    bool is_operator(string x){
        return x == "+" || x == "-" || x == "*" || x == "/";
    }

    int compute(int first,int second,string x){
        if(x == "+"){
            return first + second;
        }
        else if(x == "-"){
            return first - second;
        }
        else if (x == "*"){
            return first * second;
        }
        else{
            return (int)(first/second);
        }
    }

    int evalRPN(vector<string>& tokens) {
        stack<string> stk;
        int first,second;
        int next_value;
        for(int i=0;i<tokens.size();i++){
            if(is_operator(tokens[i])){
                second = stoi(stk.top());
                stk.pop();
                first = stoi(stk.top());
                stk.pop();

                next_value = compute(first,second,tokens[i]);               
                stk.push(to_string(next_value));
            }
            else{
                stk.push(tokens[i]);
            }
        }
        next_value = stoi(stk.top());
        stk.pop();
        return next_value;
    }
};