#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  int lx1,ly1,rx1,ry1;
  int lx2,ly2,rx2,ry2;
  cin>>t;
  while(t--){
    cin>>lx1>>ly1>>rx1>>ry1;
    cin>>lx2>>ly2>>rx2>>ry2;
    
    //checking for horizontal case
    if(lx1>rx2 || lx2>rx1){
      cout<<0<<endl;
    }
    //checking for vertical case
    else if(ry2>ly1 || ry1>ly2){
      cout<<0<<endl;
    }
    else{
      cout<<1<<endl;
    }
  }
  
  return 0;
}