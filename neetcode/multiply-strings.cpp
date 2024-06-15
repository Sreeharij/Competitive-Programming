class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1[0] == '0' || num2[0] == '0')return "0";

        int first = num1.size();
        int second = num2.size();

        string answer(first+second,'0');   
        int val;
        int digit;
        int carry;
        int i,j;
        
        for(j=second-1;j>=0;j--){
            carry = 0;
            for(i=first-1;i>=0;i--){
                val = (num1[i] - '0') * (num2[j] - '0') + (answer[i+j+1] - '0') +carry;
                digit = val%10;
                carry = val/10;
                answer[i+j+1] = digit+'0';
            }
            answer[i+j+1] = carry+'0'; // +1 is still there for index since i become -1 at the end 
        } 
        int leading = 0;
        while(answer[leading] == '0'){
            leading++;
        }
        return answer.substr(leading,first+second-leading);
    }
};