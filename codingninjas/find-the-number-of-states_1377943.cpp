void bfs(vector<int> &visited,vector<vector<int>>& roads,int current_node){
    queue<int> q;
    q.push(current_node);
    visited[current_node] = 1;
    int number;
    while(!q.empty()){
        number = q.front();
        q.pop();
        for(int i=0;i<roads.size();i++){
            if((roads[number-1][i] == 1) && (number-1 != i)){
                if(visited[i+1] == 0){
                    visited[i+1] = 1;
                    q.push(i+1);
                }
            }
        }
    }
}

int findNumOfProvinces(vector<vector<int>>& roads, int n) {
    int provinces_count = 0;
    vector<int> visited(n+1,0);
    for(int i=1;i<=n;i++){
        if(visited[i] == 0){
            provinces_count += 1;
            bfs(visited,roads,i);
        }
    }
    return provinces_count;
}