#include <bits/stdc++.h>
using namespace std;

bool check_validity(int x){
  int arr[10] = {0};
  while(x>0){
    int digit = x%10;
    x /= 10;
    arr[digit] += 1;
  }
  for(int i=0;i<10;i++){
    if (arr[i]>1){
      return false;
    } 
  }
  return true;
  
}

int main()
{
  int n;
  cin>>n;
  while(n--){
    int x;
    cin>>x;
    x++;
    while(!check_validity(x)){
      x++;
    }
    cout<<x<<endl;
  }
  
  return 0;
}