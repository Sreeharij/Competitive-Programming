//O(n) time and O(n) space where n is the length of loop + length of elements before loop
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


//O(1) space complexity
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
        int slow = n;
        int fast = comptue_result(n);

        while(slow != fast){           
            slow = comptue_result(slow);
            fast = comptue_result(comptue_result(fast));
        } 

        if(fast == 1){
            return true;
        }
        return false;
    }
};