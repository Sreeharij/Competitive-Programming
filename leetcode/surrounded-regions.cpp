class Solution {
public:
    bool is_valid(int x,int y,int rows,int cols,vector<vector<bool>>& o_touch,vector<vector<char>>& board){
        return x >= 0 && x < rows && y >= 0 && y < cols && !o_touch[x][y] && board[x][y] == 'O';
    }

    void bfs_explore(int pos_x,int pos_y,vector<vector<char>>& board,vector<vector<bool>>& o_touch,int rows,int cols){
        queue<pair<int,int>> q;
        q.push({pos_x,pos_y});
        o_touch[pos_x][pos_y] = true;
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            if(is_valid(x+1,y,rows,cols,o_touch,board)){
                o_touch[x+1][y] = true;
                q.push({x+1,y});
            }
            if(is_valid(x-1,y,rows,cols,o_touch,board)){
                o_touch[x-1][y] = true;
                q.push({x-1,y});
            }
            if(is_valid(x,y+1,rows,cols,o_touch,board)){
                o_touch[x][y+1] = true;
                q.push({x,y+1});
            }
            if(is_valid(x,y-1,rows,cols,o_touch,board)){
                o_touch[x][y-1] = true;
                q.push({x,y-1});
            }
        }   
    }

    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> o_touch(rows,vector<bool>(cols,false));

        for(int i=0;i<rows;i++){
            if(board[i][0] == 'O' && o_touch[i][0] == false){
                bfs_explore(i,0,board,o_touch,rows,cols);
            }
            if(board[i][cols-1] == 'O' && o_touch[i][cols-1] == false){
                bfs_explore(i,cols-1,board,o_touch,rows,cols);
            }
        }
        for(int j=0;j<cols;j++){
            if(board[0][j] == 'O' && o_touch[0][j] == false){
                bfs_explore(0,j,board,o_touch,rows,cols);
            }
            if(board[rows-1][j] == 'O' && o_touch[rows-1][j] == false){
                bfs_explore(rows-1,j,board,o_touch,rows,cols);
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(o_touch[i][j] == true){
                    board[i][j] = 'O';
                }
                else{
                    board[i][j] = 'X';
                }
            }
        }
    }
};