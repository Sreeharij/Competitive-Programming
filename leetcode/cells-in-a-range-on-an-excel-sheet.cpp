class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> answer;
        string temp;
        int cols = (int)(s[4] - s[1]) + 1;
        int rows = (int)(s[3] - s[0]) + 1;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                temp = "";
                temp += (char)(s[0] + i);
                temp += (char)(s[1] + j);
                answer.push_back(temp);
            }
        }
        return answer;
    }
};