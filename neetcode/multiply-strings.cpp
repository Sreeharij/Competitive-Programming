class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1[0] == '0' || num2[0] == '0')return "0";

        int first = num1.size();
        int second = num2.size();

        string answer(first+second,'0');   

        int idx_start = first+second-1;
        int idx;
        int val;
        int digit;
        int carry;

        for(int j=second-1;j>=0;j--){
            idx = idx_start;
            idx_start--;

            carry = 0;
            for(int i=first-1;i>=0;i--){
                val = (num1[i] - '0') * (num2[j] - '0') + (answer[idx] - '0') +carry;
                digit = val%10;
                carry = val/10;
                answer[idx--] = digit+'0';
            }
            answer[idx] = carry+'0';

        } 
        int leading = 0;
        while(answer[leading] == '0'){
            leading++;
        }
        return answer.substr(leading,first+second-leading);
    }
};