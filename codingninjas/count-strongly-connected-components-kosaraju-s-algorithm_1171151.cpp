#include <bits/stdc++.h>
void dfs_finish_order(vector<vector<int>> &adjacency_list,vector<int> &visited,stack<int> &stk,int number){
	visited[number] = 1;
	for(auto x: adjacency_list[number]){
		if(visited[x] == 0){
			dfs_finish_order(adjacency_list,visited,stk,x);
		}
	}
	stk.push(number);

}

void dfs_explore(vector<vector<int>> &reversed_adjacency_list,vector<int>& visited,int number){
	visited[number] = 1;
	for(auto x: reversed_adjacency_list[number]){
		if(visited[x] == 0){
			dfs_explore(reversed_adjacency_list,visited,x);
		}
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges){
	int strongly_connected_components = 0;
	vector<vector<int>> adjacency_list(v,vector<int>());
	stack<int> stk;
	for(int i=0;i<edges.size();i++){
		adjacency_list[edges[i][0]].push_back(edges[i][1]);
	}

	vector<vector<int>> reversed_adjacency_list(v,vector<int>());
	for(int i=0;i<edges.size();i++){
		reversed_adjacency_list[edges[i][1]].push_back(edges[i][0]);	
	}	

	vector<int> visited(v,0);
	for(int i=0;i<v;i++){
		if(visited[i] == 0){
			dfs_finish_order(adjacency_list,visited,stk,i);
		}
	}
	visited.assign(visited.size(),0);
	
	int top;
	while(!stk.empty()){
		top = stk.top();
		stk.pop();
		if(visited[top] == 0){
			strongly_connected_components += 1;
			dfs_explore(reversed_adjacency_list,visited,top);
		}
	}
	return strongly_connected_components;
}