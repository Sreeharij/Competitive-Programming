#include <bits/stdc++.h>
using namespace std;

int main()
{
  const int large_prime = 1000000007;
  int t,n;
  cin>>t;
  while(t--){
    cin>>n;
    int first = 1, second = 1;
    int compute;  
    
    //since every 3rd number is an even number in fibonacci series starting
    // /from the first 1. 0 1 1 2 3 5 8 13 21 34 55
    int required_index_value = 3*n; 
    for(int i=3;i<required_index_value+1;i++){
      compute = (first+second)%large_prime;
      first = second;
      second = compute;
    }
    cout<<compute<<endl;
  }
  
  return 0;
}