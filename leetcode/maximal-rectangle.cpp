class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int answer = INT_MIN;
        vector<vector<int>> number_matrix(rows,vector<int>(cols,0));
        int height,width;
        for(int j=0;j<cols;j++){
            height = 0;
            for(int i=0;i<rows;i++){
                if(matrix[i][j] == '0'){
                    height = 0;
                }
                else{
                    height++;
                    number_matrix[i][j] = height;
                }
            }
        }


        for(int row = rows-1;row >= 0;row--){
            stack<int> stk;  
            for(int i=0;i<=cols;i++){
                while(!stk.empty() && (i == cols || number_matrix[row][i] < number_matrix[row][stk.top()]) ){
                    height = number_matrix[row][stk.top()];
                    stk.pop();
                    if(stk.empty()){
                        width = i;    
                    }
                    else{
                        width = i-stk.top()-1;
                    }
                    answer = max(answer,height * width);
                }
                stk.push(i);
            }
        }
        return answer;
    }
};