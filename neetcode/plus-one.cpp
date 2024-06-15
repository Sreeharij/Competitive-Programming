class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int length = digits.size();
        int non_9_idx = -1;
        for(int i=length-1;i>=0;i--){
            if(digits[i] != 9){
                non_9_idx = i;
                break;
            }
        }      
        if(non_9_idx == -1){
            vector<int> answer(length+1,0);
            answer[0] = 1;
            return answer;
        }
        else{
            vector<int> answer(length,0);
            for(int i=0;i<non_9_idx;i++){
                answer[i] = digits[i];
            }
            answer[non_9_idx] = digits[non_9_idx]+1;
            return answer;
        }
    }
};

//CLEANER CODE

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i=digits.size()-1;i>=0;i--){
            if(digits[i] < 9){
                digits[i] += 1;
                return digits;
            }
            digits[i] = 0;
        }
        digits.push_back(0);
        digits[0] = 1;
        return digits;
    }
};