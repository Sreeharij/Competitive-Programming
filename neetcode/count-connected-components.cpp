class Solution {
public:
    void dfs_explore(int node,vector<vector<int>>& graph,vector<bool>& visited){
        visited[node] = true;
        for(auto neighbour : graph[node]){
            if(!visited[neighbour]){
                dfs_explore(neighbour,graph,visited);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n,vector<int>());

        for(auto pair:edges){
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
        }
        vector<bool> visited(n,false);
        
        int connected_count = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                connected_count += 1;
                dfs_explore(i,graph,visited);
            }
        }

        return connected_count;
    }
};
