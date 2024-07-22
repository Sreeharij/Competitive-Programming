class Solution {
public:
    bool cycle_present(vector<vector<int>>& graph,vector<bool>& recursion_stack,int node,vector<bool>& visited){
        visited[node] = true;
        recursion_stack[node] = true;
        for(auto child: graph[node]){
            if(visited[child] == false){
                if(cycle_present(graph,recursion_stack,child,visited)){
                    return true;
                }
            }
            else if(recursion_stack[child] == true){
                return true;
            }
        }
        recursion_stack[node] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        vector<vector<int>> graph(numCourses,vector<int>());
        for(auto pair: prerequisites){
            graph[pair[1]].push_back(pair[0]);
        }
        vector<bool> recursion_stack(numCourses,false);
        vector<bool> visited(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(cycle_present(graph,recursion_stack,i,visited)) return false;
            }
        }
        return true;
    }
};