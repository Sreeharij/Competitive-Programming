class Solution {
public:
    bool is_magic_sqare(vector<vector<int>>& grid,int x,int y){
        int bitset = 0;
        for(int i=-1;i<=1;i++){
            int row_sum = 0;
            int col_sum = 0;
            for(int j=-1;j<=1;j++){
                bitset |= (1<<grid[x+i][y+j]);
                row_sum += grid[x+i][y+j];
            }    
            if(row_sum != 15)return false;
            for(int j=-1;j<=1;j++){
                col_sum += grid[x+j][y+i];
            }
            if(col_sum != 15)return false;
        }
        if(grid[x-1][y-1] + grid[x][y] + grid[x+1][y+1] != 15)return false;
        if(grid[x+1][y-1] + grid[x][y] + grid[x-1][y+1] != 15)return false;
        if(bitset != 1022)return false;
        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid){
        int answer = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i=1;i<rows-1;i++){
            for(int j=1;j<cols-1;j++){
                if(grid[i][j] != 5)continue;
                if(is_magic_sqare(grid,i,j))answer++;
            }
        }

        return answer;
    }
};