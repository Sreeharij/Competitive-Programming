class Solution {
public:
    bool path_exisits(int source,int parent,int destination,vector<vector<int>>& graph,vector<int>& visited){
        visited[source] = 1;
        if(source == destination) return true;
        for(auto neighbour : graph[source]){
            if(neighbour == parent) continue;
            if(!visited[neighbour]){
                if(path_exisits(neighbour,source,destination,graph,visited)){
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n,vector<int>());
        vector<int> visited(n,0);
        for(auto pairs: edges){
            graph[pairs[0]].push_back(pairs[1]);
            graph[pairs[1]].push_back(pairs[0]);
        }

        return path_exisits(source,-1,destination,graph,visited);
    }
};