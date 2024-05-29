class Solution {
public:
    void bfs(vector<int> &visited,vector<vector<int>>& isConnected,int current_node){
        queue<int> q;
        q.push(current_node);
        visited[current_node] = 1;
        int number;
        while(!q.empty()){
            number = q.front();
            q.pop();
            for(int i=0;i<isConnected.size();i++){
                if((number-1 != i) && (isConnected[number-1][i] == 1)){
                    if(visited[i+1] == 0){
                        visited[i+1] = 1;
                        q.push(i+1);
                    }
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int answer = 0;
        vector<int> visited(isConnected.size()+1,0);
        for(int i=1;i<=isConnected.size();i++){
            if(visited[i] == 0){
                answer += 1;
                bfs(visited,isConnected,i);
            }
        }


        return answer;
    }
};