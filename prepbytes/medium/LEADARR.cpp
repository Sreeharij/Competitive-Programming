#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t,n;
  cin>>t;
  while(t--){
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    int current_max=arr[n-1];
    cout<<current_max<<" ";
    for(int i=n-2;i>=0;i--){
      if(arr[i]>=current_max){
        current_max = arr[i];
        cout<<arr[i]<<" ";
      }
    }
    cout<<endl;
    
  }
  
  return 0;
}