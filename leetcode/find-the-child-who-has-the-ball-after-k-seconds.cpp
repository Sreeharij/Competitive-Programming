class Solution {
public:
    int numberOfChild(int n, int k) {
        int rounds = k/(n-1);
        if(rounds%2 == 0){
            return 0 + k%(n-1);
        }
        return n - k%(n-1) - 1;
    }
};