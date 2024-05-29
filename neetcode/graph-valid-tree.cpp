class Solution {
public:
    bool is_valid_tree(int node,int parent,vector<vector<int>>& graph,vector<bool>& visited){
        visited[node] = true;
        bool flag = true;
        for(auto neighbour: graph[node]){
            if(neighbour == parent){
                continue;
            }
            if(!visited[neighbour]){
                if(!is_valid_tree(neighbour,node,graph,visited)){
                    flag = false;
                }
            }
            else{
                return false;
            }
        }
        return flag;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n,false);
        vector<vector<int>> graph(n,vector<int>());
        for(auto pairs: edges){
            graph[pairs[0]].push_back(pairs[1]);
            graph[pairs[1]].push_back(pairs[0]);
        }

        if(is_valid_tree(0,-1,graph,visited)){
            for(int i=0;i<n;i++){
                if(!visited[i]) return false;
            } 
            return true;
        }
        else{
            return false;
        }
    }
};
