#include <iostream>
#include <vector>
using namespace std;
int i,j,k,P,C,X,Y,K,pages_required,T,N;
bool True,False,func_call;
int main() {
    cin>>T;
    for(i=0;i<T;i++){
        bool flag;
        flag=False;
        cin>>X>>Y>>K>>N;
        int books[N][2];
        pages_required = X-Y;
        for(j=0;j<N;j++){
            cin>>P>>C;
            books[j][0]=P;
            books[j][1]=C;
        }
        for(k=0;k<N;k++){
            if (pages_required<=books[k][0]){
                if (K>=books[k][1]){
                cout<<"LuckyChef"<<endl;
                flag=1;
                break;
                }
            }

        }
        if (flag==0){
                cout<<"UnluckyChef"<<endl;
        }
    }
    return 0;
}


