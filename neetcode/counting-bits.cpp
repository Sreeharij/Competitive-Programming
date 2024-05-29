class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> answer(n+1,0);
        int current_offset = 0;
        for(int i=1;i<=n;i++){
            if((i&(i-1)) == 0){    //CONDITION FOR CHECKING POWER OF TWO
                current_offset = i;
            }
            answer[i] = answer[i-current_offset] + 1;
        }
        return answer;
    }
};


//BELOW ANSWER DOES THE ABOVE IN A SINGLE LINE

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> answer(n+1,0);
        for(int i=1;i<=n;i++){
            answer[i] = answer[i&(i-1)] + 1;
        }
        return answer;
    }
};