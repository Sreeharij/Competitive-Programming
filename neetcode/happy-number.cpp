class Solution {
public:
    int comptue_result(int n){
        int digit;
        int result = 0;
        while(n > 0){
            digit = n%10;
            n = n/10;
            result += digit*digit;
        }
        return result;
    }

    bool isHappy(int n) {
        unordered_set<int> st;
        while(true){
            st.insert(n);
            n = comptue_result(n);
            if(n == 1)return true;
            if(st.count(n)) return false;
        }
    }
};