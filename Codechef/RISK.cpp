#include <bits/stdc++.h>
using namespace std;
int directions[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

void dfs(vector<string>& grid,vector<vector<bool>>& visited,int n,int m,int& component_length,int x,int y){
    visited[x][y] = true;
    component_length++;
    for(int i=0;i<4;i++){
        int new_x = x + directions[i][0];
        int new_y = y + directions[i][1];
        if(new_x < 0 || new_y < 0 || new_x >= n || new_y >= m || grid[new_x][new_y]=='0' || visited[new_x][new_y])continue;
        dfs(grid,visited,n,m,component_length,new_x,new_y);
    }
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    vector<string> grid;
	    string s;
	    for(int i=0;i<n;i++){
	        cin>>s;
	        grid.push_back(s);
	    }
	    vector<vector<bool>> visited(n,vector<bool>(m,false));
	    vector<int> scores;
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j] == '1' && !visited[i][j]){
	                int component_length = 0;
	                dfs(grid,visited,n,m,component_length,i,j);
	                scores.push_back(component_length);
	            }
	        }
	    }
	    sort(scores.begin(),scores.end(),greater<int>());
	    int chef_score = 0;
	    for(int i=1;i<scores.size();i+=2){
	        chef_score += scores[i];
	    }
	    cout<<chef_score<<endl;
	}

}
