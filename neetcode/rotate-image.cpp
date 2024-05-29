class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = rows;
        int diag = (rows+1)/2;
        int temp;
        int layer_length;
        for(int layer=0;layer<diag;layer++){
            layer_length = rows - 2*layer;
            for(int j=layer;j<layer+layer_length-1;++j){
                temp = matrix[layer][j];
                matrix[layer][j] = matrix[rows-j-1][layer];
                matrix[rows-j-1][layer] = matrix[rows-layer-1][rows-j-1];
                matrix[rows-layer-1][rows-j-1] = matrix[j][rows-layer-1];
                matrix[j][rows-layer-1] = temp;
            }
        }
    }
};