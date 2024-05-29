class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool answer = false;
        int rows  = matrix.size();
        int cols = matrix[0].size();

        int lower_row = 0,upper_row = rows-1;
        int mid_row;
        int correct_row=0;

        while(lower_row <= upper_row){
            mid_row = (lower_row + upper_row)/2;

            if(matrix[mid_row][0] > target){
                upper_row = mid_row - 1;
            }
            else{
                correct_row = mid_row;
                lower_row = mid_row + 1;
            }
        }
        int lower_col = 0,upper_col = cols - 1;
        int mid_col,correct_col;
        while(lower_col <= upper_col){
            mid_col = (lower_col + upper_col)/2;

            if(matrix[correct_row][mid_col] == target){
                return 1;
            }
            else if(target < matrix[correct_row][mid_col]){
                upper_col = mid_col - 1;
            }
            else{
                lower_col = mid_col + 1;
            }
        }
        return answer;
    }
};