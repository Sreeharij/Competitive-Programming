class Solution {
public:
    double myPow(double x, int n){
        double answer = 1;
        int exponent = abs(n);
        for(int i=0;i<32;i++){
            if((1<<i)&exponent){
                answer = answer * x;
            }
            x = x*x;
        }
        return n < 0 ? 1/answer : answer;
    }
};


