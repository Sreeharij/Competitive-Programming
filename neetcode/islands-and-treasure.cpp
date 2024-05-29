//DFS APPROACH BELOW
class Solution {
public:
    bool is_valid(int x,int y,int rows,int cols,vector<vector<int>>& grid){
        if(x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] != -1){
            return true;
        }
        return false;
    }

    void dfs(int x,int y,int rows,int cols,vector<vector<int>>& grid,int distance){
        if(grid[x][y] == 0 && distance!=0){
            return;
        }
        if(distance < grid[x][y] || grid[x][y] == 0){
            grid[x][y] = distance;
        }
        else{
            return;
        }
        if(is_valid(x+1,y,rows,cols,grid)){
            dfs(x+1,y,rows,cols,grid,grid[x][y]+1);
        }
        if(is_valid(x-1,y,rows,cols,grid)){
            dfs(x-1,y,rows,cols,grid,grid[x][y]+1);
        }
        if(is_valid(x,y+1,rows,cols,grid)){
            dfs(x,y+1,rows,cols,grid,grid[x][y]+1);
        }
        if(is_valid(x,y-1,rows,cols,grid)){
            dfs(x,y-1,rows,cols,grid,grid[x][y]+1);
        }
    }      

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<pair<int,int>> tressure;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 0){
                    tressure.push_back({i,j});
                }
            }
        }
        for(auto x: tressure){
            int distance = 0;
            dfs(x.first,x.second,rows,cols,grid,distance);
        }
    }
};



//BFS APPROACH BELOW
class Solution {
private:
    int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    bool is_valid(int x,int y,int rows,int cols,vector<vector<int>>& grid){
        if(x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == INT_MAX){
            return true;
        }
        return false;
    }  

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int current_row = q.front().first;
            int current_col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int x = current_row + directions[i][0];
                int y = current_col + directions[i][1];
                if(is_valid(x,y,rows,cols,grid)){
                    grid[x][y] = grid[current_row][current_col] + 1;
                    q.push({x,y});
                }
            }
        }
    }
};
