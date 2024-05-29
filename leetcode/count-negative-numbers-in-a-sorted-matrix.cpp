class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int answer = 0;
        int left,right,mid,start_idx;
        for(int i=0;i<rows;i++){
            left = 0,right = cols - 1;
            start_idx = cols;
            while(left <= right){
                mid = (left + right)/2;
                if(grid[i][mid] < 0){
                    start_idx = mid;
                    right = mid - 1;
                }
                else{
                    left = mid + 1;
                }
            }
            answer += cols - start_idx;
        }
        return answer;
    }
};