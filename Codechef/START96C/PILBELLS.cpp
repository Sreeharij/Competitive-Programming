#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int n,x,k,p;
    while(t--){
        cin>>n>>x>>k>>p;
        int mana = p;
        if(k>=x){
            mana += 10*x;
            mana += (k-x) * 5; 
        }
        else{
            mana += 10*k;
        }
        if(n==k){
            mana += 20;
        }
        cout<<mana<<endl;
    }
    return 0;
}