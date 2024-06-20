class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(i < rows-1 && grid[i][j] != grid[i+1][j])return false;
                if(j < cols-1 && grid[i][j] == grid[i][j+1])return false;
            }
        }
        return true;
    }
};