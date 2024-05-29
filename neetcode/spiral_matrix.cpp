class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int total_layers = rows<cols?rows:cols;
        total_layers = (total_layers+1)/2;
        printf("total: %d",total_layers);
        vector<int>final_arr(rows*cols);
        int idx = 0;
        for(int layer=0;layer<total_layers;layer++){
            for(int i=layer;i<cols-layer;i++){
                final_arr[idx] = matrix[layer][i];
                idx++;
            }
            for(int j=layer+1;j<rows-layer;j++){
                final_arr[idx] = matrix[j][cols-layer-1];
                idx++;
            }

            if(layer<rows-layer-1){
                for(int k=cols-layer-2;k>=layer;k--){
                    final_arr[idx] = matrix[rows-layer-1][k];
                    idx++;
                }
            }
            if(layer<cols-layer-1){
                for(int l=rows-layer-2;l>layer;l--){
                    final_arr[idx] = matrix[l][layer];
                    idx++;
                }
            }
            
        }   
        return final_arr;
    }
};
