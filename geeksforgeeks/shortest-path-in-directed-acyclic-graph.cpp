//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<vector<pair<int,int>>> graph(N,vector<pair<int,int>>());
        vector<int> incoming(N,0);
        for(auto x: edges){
            graph[x[0]].push_back({x[1],x[2]});
            incoming[x[1]]++;
        }
        vector<int> topo_sort(N,0);
        queue<int> q;
        for(int i=0;i<N;i++){
            if(incoming[i] == 0){
                q.push(i);
            }
        }
        int idx=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo_sort[idx++] = node;
            for(auto neighbour: graph[node]){
                int val = neighbour.first;
                incoming[val]--;
                if(incoming[val] == 0){
                    q.push(val);
                }
            }
        }
        int required_idx = 0;
        for(int i=0;i<N;i++){
            if(topo_sort[i] == 0){
                required_idx = i;
                break;
            }
        }
        vector<int> shortest_paths(N,INT_MAX);
        shortest_paths[0] = 0;
        for(int i=required_idx;i<N;i++){
            int node = topo_sort[i];
            for(auto x: graph[node]){
                int neighbour = x.first;
                int weight = x.second;
                if(shortest_paths[node] == INT_MAX)continue; //FOR HANDLING ELEMENTS IN TOPO SORT THAT HAVE NO CONNETION TO NODE 0 BUT COMES AFTER 0
                if(shortest_paths[node] + weight < shortest_paths[neighbour]){
                    shortest_paths[neighbour] = shortest_paths[node] + weight;
                }
            }
        }
        for(int i=0;i<N;i++){
            if(shortest_paths[i] == INT_MAX)shortest_paths[i] = -1;
        }
        return shortest_paths;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends