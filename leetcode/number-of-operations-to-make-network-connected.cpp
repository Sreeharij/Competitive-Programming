class Solution {
public:
    void dfs(vector<vector<int>>& graph,vector<bool>& visited,int node){
        visited[node] = true;
        for(int neighbour: graph[node]){
            if(!visited[neighbour]){
                dfs(graph,visited,neighbour);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n,vector<int>());
        for(auto pair: connections){
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
        }
        vector<bool> visited(n,false);
        vector<int> disjoint_set(n,-1);
        int cc = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                cc++;
                connect(graph,visited,i);
            }
        }
        int edges = connections.size();
        if(edges < n-1) return -1;
        return cc-1;
    }
};