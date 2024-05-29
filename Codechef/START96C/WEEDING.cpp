#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int n,m,k;
    while(t--){
        cin>>n>>m>>k;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(arr[n-1] + k - 1 <=m){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}