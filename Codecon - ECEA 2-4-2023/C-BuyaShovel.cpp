#include <iostream>
using namespace std;

int main(){
    int k,r;
    cin>>k>>r;
    int remainder = k%10;
    if(remainder==r || remainder==0){
        cout<<1<<endl;
    }
    else{
        int counter = 1;
        for(int i=2;i<10;i++){
            counter++;
            if((remainder*i)%10 == 0 || (remainder*i)%10 == r){
                break;
            }
        }
        cout<<counter<<endl;
    }
    return 0;
}