class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int answer = 0;
        for(int i=0;i<operations.size();i++){
            if(count(operations[i].begin(),operations[i].end(),'+')){
                answer++;
            }
            else{
                answer--;
            }
        }
        return answer;
    }
};