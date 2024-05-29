#include <iostream>
#include <cmath>
#include <deque>
using namespace std;
int Testcases,test,N,i,j,num;
int main() {
    cin>>Testcases;
    for(test=0;test<Testcases;test++){
        cin>>N;
        int grid[N][N] = {};
        num = pow(N,2)/2;
        deque<int>even;
        deque<int>odd;

        for(i=1;i<(pow(N,2)+1);i+=2){odd.push_back(i);}

        for (i=2;i<(pow(N,2)+1);i+=2) {even.push_back(i);}

        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                if (i%2==0){
                    if (j%2==0){
                        grid[i][j]=odd[0];
                        odd.pop_front();
                    }
                    else{
                        grid[i][j]=even[0];
                        even.pop_front();
                    }
                }
                else{
                    if (j%2!=0){
                        grid[i][j]=odd[0];
                        odd.pop_front();
                    }
                    else{
                        grid[i][j]=even[0];
                        even.pop_front();
                    }
                }
            }
        }
                for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }

    }
    return 0;

}
