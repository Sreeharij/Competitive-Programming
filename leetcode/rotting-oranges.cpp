class Solution {
public:
    bool is_valid(int x,int y,int rows,int cols){
        return x >= 0 && x < rows && y >= 0 && y < cols;
    }

    int pos_to_num(int x,int y,int rows,int cols){
        return x*cols + y;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int minutes = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> visited(rows*cols,0);
        queue<int> q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 2){
                    q.push(pos_to_num(i,j,rows,cols));
                }
            }
        }
        int number;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                number = q.front();
                int x = number/cols;
                int y = number%cols;
                q.pop();
                if(is_valid(x,y+1,rows,cols) && grid[x][y+1] == 1){
                    grid[x][y+1] = 2;
                    q.push(number+1);
                }
                if(is_valid(x,y-1,rows,cols) && grid[x][y-1] == 1){
                    grid[x][y-1] = 2;
                    q.push(number-1);
                }
                if(is_valid(x+1,y,rows,cols) && grid[x+1][y] == 1){
                    grid[x+1][y] = 2;
                    q.push(number+cols);
                }
                if(is_valid(x-1,y,rows,cols) && grid[x-1][y] == 1){
                    grid[x-1][y] = 2;
                    q.push(number-cols);
                }
            }
            minutes += 1;
        }
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return minutes ? minutes-1:0;
    }
};

