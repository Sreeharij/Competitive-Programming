#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int allowed_max = arr[n-1] - 1;
  int counter = arr[n-1];
  for(int i=n-2;i>=0;i--){
    if (allowed_max<0){
      break;
    }
    if (arr[i]<=allowed_max){
      counter += arr[i];
      allowed_max = arr[i] - 1;
    }
    else{
      counter += allowed_max;
      allowed_max -= 1;
    }
  }
  cout<<counter<<endl;
  return 0;
}