#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t,A,B,C;
  cin>>t;
  while(t--){
    cin>>A>>B>>C;
    if (C==0){
      if (A==B){  
        cout<<"YES\n";
      }
      else{
        cout<<"NO\n";
      }
    }
    else if ((B-A)%C==0){
      if(((B-A)/C+1)>0){
        cout<<"YES\n";
      }
      else{
        cout<<"NO\n";
      }
    }
    else{
      cout<<"NO\n";
    }
    
  }
  
  return 0;
}