class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> topo_sort;
        vector<vector<int>> graph(numCourses,vector<int>());
        vector<int> incoming_edges(numCourses,0);
        for(auto pair: prerequisites){
            graph[pair[1]].push_back(pair[0]);
            incoming_edges[pair[0]] += 1;
        }
        
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(incoming_edges[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo_sort.push_back(node);
            for(auto neighbour : graph[node]){
                incoming_edges[neighbour] -= 1;
                if(incoming_edges[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }
        if(topo_sort.size() != numCourses) return vector<int>();
        return topo_sort;   
    }
};