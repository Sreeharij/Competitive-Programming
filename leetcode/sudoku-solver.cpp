class Solution{
private:
    bool rows[9][9] = {false};
    bool cols[9][9] = {false};
    bool box[9][9] = {false};
    bool PLACE = true;
    bool REMOVE = false;
public:
    bool is_valid(vector<vector<char>>& board,int x,int y,char val){
        int number = val - '1';
        return !(rows[x][number] || cols[y][number] || box[x/3 * 3 + y/3][number]);
    }

    void put_value(vector<vector<char>>& board,int x,int y,char val,bool FLAG){
        int number = val - '1';
        board[x][y] = FLAG ? val : '.';
        rows[x][number] = FLAG;
        cols[y][number] = FLAG;
        box[x/3 * 3 + y/3][number] = FLAG;
    }

    bool backtrack(vector<vector<char>>& board,vector<pair<int,int>>& initial_empty_cells,int idx){
        if(idx == initial_empty_cells.size()){
            return true;
        }
        int x = initial_empty_cells[idx].first;
        int y = initial_empty_cells[idx].second;
        for(char val='1';val<='9';val++){
            if(is_valid(board,x,y,val)){
                put_value(board,x,y,val,PLACE);
                if(backtrack(board,initial_empty_cells,idx+1)){
                    return true;
                }
                put_value(board,x,y,val,REMOVE);
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board){
        vector<pair<int,int>> initial_empty_cells;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.'){
                    initial_empty_cells.push_back({i,j});
                }
                else{
                    int number = board[i][j] - '1';
                    rows[i][number] = true;
                    cols[j][number] = true;
                    box[i/3 * 3 + j/3][number] = true;
                }
            }
        }
        backtrack(board,initial_empty_cells,0);
    }
};