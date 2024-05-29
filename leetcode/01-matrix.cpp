class Solution{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat){      
        int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> distance_matrix(rows,vector<int>(cols,INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    distance_matrix[i][j] = 0;
                }
            }
        }
        int x,y,new_x,new_y;
        vector<pair<int,int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while(!q.empty()){
            x = q.front().first;
            y = q.front().second;
            q.pop();
            for(const auto& coord:directions){
                new_x = x + coord.first;
                new_y = y + coord.second;
                if(new_x >= 0 && new_x < rows && new_y >= 0 && new_y < cols && distance_matrix[new_x][new_y] > distance_matrix[x][y] + 1){
                    distance_matrix[new_x][new_y] = distance_matrix[x][y] + 1;
                    q.push({new_x,new_y});
                }
            }            
        }
        return distance_matrix;
    }
};