#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t,n;
  cin>>t;
  while(t--){
    cin>>n;
    int arr[n];
    bool flag=1;
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    if(arr[0]>arr[1]){
      cout<<0<<" ";
      flag = 0;
    }
    for(int i=1;i<n-1;i++){
      if (arr[i]>arr[i-1] && arr[i]>arr[i+1]){
        cout<<i<<" ";
        flag=0;
      }
    }
    if(arr[n-1]>arr[n-2]){
      cout<<n-1;
      flag = 0;
    }
    if (flag){
      cout<<-1;
    }
    cout<<endl;
  }
  
  return 0;
}