#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    int x,y,z;
    while(t--){
        cin>>x>>y>>z;
        if((x*y)%z==0){
            cout<<x*y<<" "<<z<<endl;
        }
        else if((x*z)%y==0){
            cout<<x*z<<" "<<y<<endl;
        }
        else if((y*z)%x==0){
            cout<<y*z<<" "<<x<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
}