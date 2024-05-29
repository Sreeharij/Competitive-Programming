#include <bits/stdc++.h>
using namespace std;

void func(int n){
    for(int i=2;i<sqrt(n)+1;i++){
        if(n%i==0){
            cout<<n/i<<" "<<n-n/i<<endl;
            return;
        }
    }
    cout<<1<<" "<<n-1<<endl;
    return;
}

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        func(n);
    }
    return 0;
}