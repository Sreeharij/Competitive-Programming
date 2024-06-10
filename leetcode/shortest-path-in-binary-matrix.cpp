class Solution {
private:
    int directions[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
public:
    bool is_valid(int x,int y,int n,vector<vector<bool>>& visited,vector<vector<int>>& grid){
        if(x < 0 || y < 0 || x >= n || y >= n || visited[x][y] || grid[x][y]==1)return false;
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid){
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)return -1;
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        q.push({0,0});
        visited[0][0] = true;
        int length = 0;
        while(!q.empty()){
            int level_length = q.size();
            length++;
            for(int i=0;i<level_length;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x == n-1 && y == n-1)return length;
                for(int i=0;i<8;i++){
                    int new_x = x + directions[i][0];
                    int new_y = y + directions[i][1];
                    if(is_valid(new_x,new_y,n,visited,grid)){
                        visited[new_x][new_y] = true;
                        q.push({new_x,new_y});
                    }
                }
            }
        }
        return -1;
    }
};