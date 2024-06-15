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

//OPTIMUM SOLUTION AS SEEN ONLINE GIVEN BELOW
class Solution {
public:
    string multiply(string num1, string num2) {
        int first = num1.size();
        int second = num2.size();

        string answer(first+second,'0');   
        int val;        

        for(int j=second-1;j>=0;j--){
            for(int i=first-1;i>=0;i--){
                val = (num1[i] - '0') * (num2[j] - '0') + (answer[i+j+1] - '0');
                answer[i+j+1] = val%10 +'0';
                answer[i+j] += val/10; //NOTICE THE += THE COMPUTATION IS CLEVERLY STORED HERE FOR LATER USE
            }
        } 
        for(int i=0;i<first+second;i++){
            if(answer[i] != '0'){
                return answer.substr(i);
            }
        }
        return "0";
    }
};