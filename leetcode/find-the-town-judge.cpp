class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> graph(n+1,vector<int>());
        for(auto x: trust){
            graph[x[0]].push_back(x[1]);
        }
        int required_node = -1;
        for(int i=1;i<=n;i++){
            if(graph[i].empty()){
                required_node = i;
            }
        }
        if(required_node == -1){
            return -1;
        }
        for(int i=1;i<=n;i++){
            if(i == required_node) continue;
            bool present = false;
            for(auto val : graph[i]){
                if(val == required_node){
                    present = true;
                }
            }
            if(!present){
                return -1;
            }
        }
        return required_node;
    }
};