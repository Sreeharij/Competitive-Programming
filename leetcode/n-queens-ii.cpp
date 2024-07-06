class Solution {
public:
    void backtrack(int n,int row,int col_mask,int diag1,int diag2,int& answer){
        if(row == n){
            answer++;
            return;
        }
        for(int j=0;j<n;j++){
            if((1<<j)&col_mask || (1<<(row+j)&diag1) || (1<<(row-j+n)&diag2))continue;
            backtrack(n,row+1,col_mask | (1<<j),diag1 | (1<<(row+j)), diag2 | (1<<(row-j+n)), answer);
        }
    }

    int totalNQueens(int n) {
        int answer = 0;
        backtrack(n,0,0,0,0,answer);
        return answer;
    }
};