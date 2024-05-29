class Solution {
public:
    int climbStairs(int n) {
        int answer = 0;
        for(int i=0;i<n/2+1;i++){
            answer += nCr(n-i,i);
        }
        return answer;   
    }

    long long nCr(int n,int r){
        if(r==0){
            return 1;
        }
        long long result = n;
        for(int i=0;i<r-1;i++){
            n--;
            result *= n;
            result /= i+2;
        }

        return result;
    }
};