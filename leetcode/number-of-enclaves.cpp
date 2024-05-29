class Solution {
public:
    bool valid_idx(int x,int y,int rows,int cols,vector<vector<int>>& grid,vector<vector<bool>>& visited){
        return x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 1 && !visited[x][y];
    }

    void bfs_explore(int pos_x,int pos_y,vector<vector<int>>& grid,vector<vector<bool>>& visited,int rows,int cols){
        queue<pair<int,int>> q;
        q.push({pos_x,pos_y});
        int x,y;
        visited[pos_x][pos_y] = true;
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            x = p.first;
            y = p.second;
            if(valid_idx(x+1,y,rows,cols,grid,visited)){
                q.push({x+1,y});
                visited[x+1][y] = true;
            }
            if(valid_idx(x-1,y,rows,cols,grid,visited)){
                q.push({x-1,y});
                visited[x-1][y] = true;
            }
            if(valid_idx(x,y+1,rows,cols,grid,visited)){
                q.push({x,y+1});
                visited[x][y+1] = true;
            }
            if(valid_idx(x,y-1,rows,cols,grid,visited)){
                q.push({x,y-1});
                visited[x][y-1] = true;
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int answer = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        for(int j=0;j<cols;j++){
            if(!visited[0][j] && grid[0][j] == 1){
                bfs_explore(0,j,grid,visited,rows,cols);
            }
            if(!visited[rows-1][j] && grid[rows-1][j] == 1){
                bfs_explore(rows-1,j,grid,visited,rows,cols);
            }
        }
        for(int i=0;i<rows;i++){
            if(!visited[i][0] && grid[i][0] == 1){
                bfs_explore(i,0,grid,visited,rows,cols);
            }
            if(!visited[i][cols-1] && grid[i][cols-1] == 1){
                bfs_explore(i,cols-1,grid,visited,rows,cols);
            }
        }
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    answer += 1;
                }
            }
        }
        return answer;
    }
};