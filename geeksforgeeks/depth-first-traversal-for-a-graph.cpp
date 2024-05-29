//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    void dfs_util(vector<int> adj[],vector<int> &visited,vector<int> &answer,int current_node){
        for(int i=0;i<adj[current_node].size();i++){
            if(visited[adj[current_node][i]] == 0){
                visited[adj[current_node][i]] = 1;
                answer.push_back(adj[current_node][i]);
                dfs_util(adj,visited,answer,adj[current_node][i]);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> visited(V,0);   
        vector<int> answer;
        visited[0] = 1;
        answer.push_back(0);
        dfs_util(adj,visited,answer,0);
        
        return answer;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends