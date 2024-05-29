class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<int> q;
        vector<int> color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i] != -1) continue;
            q.push(i);
            color[i] = 0;

            while(!q.empty()){
                int number = q.front();
                q.pop();
                
                for(auto neighbour:  graph[number]){
                    if(color[neighbour] == color[number]) return false;
                    if(color[neighbour] == -1){
                        color[neighbour] = !(color[number]);
                        q.push(neighbour);
                    }
                }
            }
        }
        return true;
    }
};