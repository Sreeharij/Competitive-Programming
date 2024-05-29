#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n%2==0){
        if((n/2)%2==0){
            cout<<0<<endl;
        }
        else{
            cout<<1<<endl;
        }
    }
    else{
        if(((n+1)/2)%2==0){
            cout<<0<<endl;
        }
        else{
            cout<<1<<endl;
        }
    }
    return 0;
}