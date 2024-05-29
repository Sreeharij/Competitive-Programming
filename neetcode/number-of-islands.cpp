class Solution {
public:
    void dfs_explore(vector<vector<bool>>& visited,vector<vector<char>>& grid,int pos_x,int pos_y){
        if(pos_x >=0 && pos_x < grid.size() && pos_y >= 0 && pos_y < grid[0].size() && !visited[pos_x][pos_y] && grid[pos_x][pos_y] == '1')
            visited[pos_x][pos_y] = true;   
            dfs_explore(visited,grid,pos_x-1,pos_y);
            dfs_explore(visited,grid,pos_x+1,pos_y);
            dfs_explore(visited,grid,pos_x,pos_y-1);
            dfs_explore(visited,grid,pos_x,pos_y+1);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int total_islands = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols,false)); 
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    total_islands += 1;
                    dfs_explore(visited,grid,i,j);
                }
            }
        }
        return total_islands;
    }
};