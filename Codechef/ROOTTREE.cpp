#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,n,u,v;
    cin>>t;
    while(t--){
        cin>>n;
        vector<vector<int>> graph(n+1,vector<int>());
        int incoming[n+1]={0};
        for(int i=0;i<n-1;i++){
            cin>>u>>v;
            graph[u].push_back(v);
            incoming[v]++;
        }
        int answer = 0;
        for(int i=1;i<=n;i++){
            if(incoming[i] == 0)answer++;
        }
        cout<<--answer<<endl;
    }

}
