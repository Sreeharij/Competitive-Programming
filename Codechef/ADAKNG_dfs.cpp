#include <bits/stdc++.h>
using namespace std;

int directions[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int main() {
	int t;
	cin>>t;
	while(t--){
	    int r,c,k;
	    cin>>r>>c>>k;
	    r -= 1;
	    c -= 1;
	    int count = 0;
	    queue<pair<int,int>> q;
	    q.push({r,c});
	    int current_level = 1;
	    vector<vector<bool>> visited(8,vector<bool>(8,false));
	    visited[r][c] = true;
	    while(!q.empty()){
	        int x = q.front().first;
	        int y = q.front().second;
	        q.pop();
	        current_level--;
	        count++;
	        for(int i=0;i<8;i++){
	            int new_x = x + directions[i][0];
	            int new_y = y + directions[i][1];
	            if(new_x < 0 || new_y < 0 || new_x >=8 || new_y >= 8 || visited[new_x][new_y])continue;
	            visited[new_x][new_y] = true;
	            q.push({new_x,new_y});
	        }
	        if(current_level == 0){
	            k--;      
	            current_level = q.size();
	        }
	        if(k == -1)break;
	    }
	    cout<<count<<endl;
	}

}
