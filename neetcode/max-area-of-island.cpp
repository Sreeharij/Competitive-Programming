class Solution {
public:
    void dfs_explore(int pos_x,int pos_y,vector<vector<int>>& grid,vector<vector<bool>>& visited,int rows,int cols,int& current_area){
        if(pos_x >=0 && pos_x < rows && pos_y >= 0 && pos_y < cols && !visited[pos_x][pos_y] && grid[pos_x][pos_y] == 1){
            visited[pos_x][pos_y] = true;
            current_area += 1;
            dfs_explore(pos_x-1,pos_y,grid,visited,rows,cols,current_area);
            dfs_explore(pos_x+1,pos_y,grid,visited,rows,cols,current_area);
            dfs_explore(pos_x,pos_y+1,grid,visited,rows,cols,current_area);
            dfs_explore(pos_x,pos_y-1,grid,visited,rows,cols,current_area);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid){
        int max_area = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    int current_area = 0;
                    dfs_explore(i,j,grid,visited,rows,cols,current_area);
                    max_area = max(current_area, max_area);
                }
            }
        }
        return max_area;
    }
};