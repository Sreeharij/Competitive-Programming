class Solution {
public:
    int compute_position(int x,int y,int rows,int cols){
        return x*cols + y;
    }

    bool is_valid(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

    void dfs(vector<int> &visited, vector<vector<int>>& image, int x, int y, int color, int rows, int cols,int original) {
    if (is_valid(x, y, rows, cols) && visited[compute_position(x, y, rows, cols)] == 0 && image[x][y] == original) {
        visited[compute_position(x, y, rows, cols)] = 1;
        image[x][y] = color;
        dfs(visited, image, x - 1, y, color, rows, cols,original);
        dfs(visited, image, x + 1, y, color, rows, cols,original);
        dfs(visited, image, x, y - 1, color, rows, cols,original);
        dfs(visited, image, x, y + 1, color, rows, cols,original);
    }
}

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size();
        int cols = image[0].size();
        vector<int> visited(rows*cols,0);
        dfs(visited,image,sr,sc,color,rows,cols,image[sr][sc]);

        return image;
    }
};
