#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main()
{
  int t,n;
  cin>>t;
  while(t--){
    cin>>n;
    int counter = 0;
    int n_copy = n;
    int power = log10(n_copy) + 1;
    while(n_copy > 0){
        int digit = n_copy%10;
        n_copy /= 10;
        counter += pow(digit,power);
    }

    if(counter==n){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
    
 
    
  }
  
  return 0;
}