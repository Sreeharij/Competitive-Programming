//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    private:
        int x_dir[4] = {-1,1,0,0};
        int y_dir[4] = {0,0,1,-1};
        char letter[4] = {'U','D','R','L'};
        
        bool is_valid(vector<vector<int>> &m,int x,int y,int n,vector<vector<bool>>& visited){
            if(x < 0 || y < 0 || x >= n || y >= n || m[x][y] == 0 || visited[x][y]){
                return false;
            }
            return true;
        }
        
    public:
    void dfs(vector<vector<int>>& m,vector<string>& answer,string& route,int x,int y,int n,vector<vector<bool>>& visited){
        if(x == n-1 && y == n-1){
            answer.push_back(route);
            return;
        }
        visited[x][y] = true;
        
        for(int i=0;i<4;i++){
            int new_x = x + x_dir[i];
            int new_y = y + y_dir[i];
            if(is_valid(m,new_x,new_y,n,visited)){
                route.push_back(letter[i]);
                dfs(m,answer,route,new_x,new_y,n,visited);
                route.pop_back();
            }
        }
        visited[x][y] = false;
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> answer;
        if(m[0][0] == 0) return answer;
        string route = "";
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        dfs(m,answer,route,0,0,n,visited);
        return answer;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends