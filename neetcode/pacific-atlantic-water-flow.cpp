class Solution {
public:
    int directions[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

    bool is_valid(int x,int y,vector<vector<int>>& heights,vector<vector<bool>>& visited,int current){
        if(x < 0 || y < 0 || x >= heights.size() || y >= heights[0].size() || visited[x][y] || current > heights[x][y])return false;
        return true;
    }

    void dfs(vector<vector<int>>& heights,vector<vector<bool>>& visited,int x,int y){
        visited[x][y] = true;
        for(int i=0;i<4;i++){
            int new_x = x + directions[i][0];
            int new_y = y + directions[i][1];
            if(is_valid(new_x,new_y,heights,visited,heights[x][y])){
                dfs(heights,visited,new_x,new_y);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights){
        vector<vector<int>> answer;

        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> pacific(rows,vector<bool>(cols,false));
        vector<vector<bool>> atlantic(rows,vector<bool>(cols,false));

        for(int i=0;i<rows;i++){
            if(!pacific[i][0]) dfs(heights,pacific,i,0,false);
            if(!atlantic[i][cols-1]) dfs(heights,atlantic,i,cols-1,true);
        }
        for(int j=1;j<cols;j++){
            if(!pacific[0][j]) dfs(heights,pacific,0,j,false);
            if(!atlantic[rows-1][j]) dfs(heights,atlantic,rows-1,j,true);
        }
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(pacific[i][j] && atlantic[i][j])answer.push_back({i,j});
            }
        }

        return answer;
    }
};