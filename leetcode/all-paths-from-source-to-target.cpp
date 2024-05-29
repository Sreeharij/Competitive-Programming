class Solution {
public:
    void get_path(int source,int parent,int destination,vector<vector<int>>& graph,vector<vector<int>>& all_paths,vector<bool>& visited,vector<int>& path){
        if(source == destination){
            all_paths.push_back(path);
            return;
        }
        for(auto neighbour : graph[source]){
            if(neighbour == parent) continue;
            if(!visited[neighbour]){
                visited[neighbour] = true;
                path.push_back(neighbour);
                get_path(neighbour,source,destination,graph,all_paths,visited,path);
                visited[neighbour] = false;
                path.pop_back();
            }
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> all_paths;
        vector<bool> visited(n,false);
        vector<int> path;
        path.push_back(0);
        get_path(0,-1,n-1,graph,all_paths,visited,path);
        
        return all_paths;
    }
};