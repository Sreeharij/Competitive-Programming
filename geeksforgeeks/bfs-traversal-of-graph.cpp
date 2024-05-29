//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> answer;
        vector<int> visited(V,0);
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        answer.push_back(0);
        int current;
        while(!q.empty()){
            current = q.front();
            q.pop();
            for(int i=0;i<adj[current].size();i++){
                int node = adj[current][i];
                if(visited[node] == 0){
                    answer.push_back(node);
                    visited[node] = 1;
                    q.push(node);
                }
            }
        }
        return answer;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends