class Solution {
public:
    int getSum(int a, int b) {
        int a_bit,b_bit;
        int answer = 0;
        int carry = 0;
        for(int i=0;i<32;i++){
            a_bit = (a & 1 << i);
            b_bit = (b & 1 << i);
            answer = answer | (a_bit ^ b_bit)^carry;
            carry = (a_bit & carry) | (b_bit & carry) | (a_bit & b_bit);
            carry = carry << 1;
        }
        return answer;
    }
};

class Solution {
public:
    int getSum(int a, int b) {
        int carry;
        while(b != 0){
            carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }
        return a;
    }
};