class Solution {
public:
    void find_bridges(vector<vector<int>>& graph_adjacency_list,vector<int>& ids_array,vector<int>& low_links_array,vector<int>& visited,int& id_counter,vector<vector<int>>& bridges,int node,int parent){
        visited[node] = 1;
        ids_array[node] = low_links_array[node] = id_counter;
        id_counter++;  

        for(auto neighbour : graph_adjacency_list[node]){
            if(neighbour == parent) continue;
            if(visited[neighbour] == 0){
                find_bridges(graph_adjacency_list, ids_array, low_links_array, visited, id_counter, bridges, neighbour, node);
                low_links_array[node] = min(low_links_array[node], low_links_array[neighbour]);
                if(low_links_array[neighbour] > ids_array[node]){
                    bridges.push_back({node,neighbour});
                }
            }
            else{
                low_links_array[node] = min(low_links_array[node], low_links_array[neighbour]);
            }        
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph_adjacency_list(n,vector<int>());
        vector<vector<int>> bridges;
        vector<int> visited(n,0);
        for(int i=0;i<connections.size();i++){
            graph_adjacency_list[connections[i][0]].push_back(connections[i][1]);
            graph_adjacency_list[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int> ids_array(n,0);
        vector<int> low_links_array(n,0);
        int id_counter = 0;
        find_bridges(graph_adjacency_list, ids_array, low_links_array, visited, id_counter, bridges, 0, -1);
        return bridges;
    }
};