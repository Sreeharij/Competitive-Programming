class Solution {
public:
    int reverse(int x){
        if(x == INT_MAX || x == INT_MIN)return 0;
        int answer = 0;
        int digit;
        while(x != 0){
            digit = x % 10;
            x /= 10;
            if(answer > INT_MAX/10 || answer < INT_MIN/10)return 0;
            answer = answer * 10 + digit;
            cout<<answer<<endl;
        }
        return answer;
    }
};