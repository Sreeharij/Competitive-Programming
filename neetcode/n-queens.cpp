//Uses bitmasking for storing whether Q is already placed in col, forward diagonal or backward diagonal
class Solution {
public:
    void backtrack(vector<vector<string>>& answer,vector<string>& board,int n,int row,int col_mask,int right_diag_mask,int left_diag_mask){
        if(row == n){
            answer.push_back(board);
            return;
        }
        for(int col=0;col<n;col++){
            if((1<<col & col_mask) || (1<<(row+col) & right_diag_mask) || (1<<(row-col+n-1) & left_diag_mask))continue;
            board[row][col] = 'Q';
            backtrack(answer,board,n,row+1,col_mask | 1 << col,1<<(row+col) | right_diag_mask,1<<(row-col+n-1) | left_diag_mask);
            board[row][col] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> answer;
        vector<string> board(n,string(n,'.'));
        backtrack(answer,board,n,0,0,0,0);
        return answer;
    }
};