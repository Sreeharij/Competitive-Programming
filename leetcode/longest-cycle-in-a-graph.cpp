class Solution {
public:
    void dfs(vector<int>& edges,vector<int>& visited,int node,int depth,int& longest_cycle){
        if(node == -1)return;
        if(visited[node] > 0){
            longest_cycle = max(longest_cycle,depth-visited[node]);
            visited[node] = -visited[node];
            return;
        }
        else if(visited[node] < 0)return;

        visited[node] = depth;
        dfs(edges,visited,edges[node],depth+1,longest_cycle);
        visited[node] = -visited[node];

    }

    int longestCycle(vector<int>& edges) {
        int longest_cycle = -1;
        int length = edges.size();
        vector<int> visited(length,0);

        for(int i=0;i<length;i++){
            if(!visited[i]){
                dfs(edges,visited,i,1,longest_cycle);
            }
        }

        return longest_cycle;
    }
};