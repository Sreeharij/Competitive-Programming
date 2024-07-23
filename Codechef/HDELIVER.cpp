#include <bits/stdc++.h>
using namespace std;

int find(int x,vector<int>& disjoint_set){
    if(disjoint_set[x] < 0)return x;

    disjoint_set[x] = find(disjoint_set[x],disjoint_set);
    return disjoint_set[x]; 
}

void merge(int u,int v,vector<int>& disjoint_set){
    int u_parent = find(u,disjoint_set);
    int v_parent = find(v,disjoint_set);
    
    if(u_parent != v_parent){
        if(abs(disjoint_set[u_parent]) < abs(disjoint_set[v_parent])){
            disjoint_set[v_parent] += disjoint_set[u_parent];
            disjoint_set[u_parent] = v_parent;
        }
        else{
            disjoint_set[u_parent] += disjoint_set[v_parent];
            disjoint_set[v_parent] = u_parent;
        }
    }
}

int main(){
    int t,n,m,a,b,q;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<int> disjoint_set(n,-1);
        for(int i=0;i<m;i++){
            cin>>a>>b;
            merge(a,b,disjoint_set);    
        }
        cin>>q;
        for(int i=0;i<q;i++){
            cin>>a>>b;
            if(find(a,disjoint_set) == find(b,disjoint_set))cout<<"YO"<<endl;
            else cout<<"NO"<<endl;
        }
    }

    return 0;
}

