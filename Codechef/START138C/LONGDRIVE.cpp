#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        int answer = INT_MAX;
        if(x == y){
            cout<<0<<endl;
            continue;
        }
        for(int i=y+1;i<=100;i++){
            if((10*(y-x))%(i-y) == 0){
                answer = min(answer,(10*(y-x))/(i-y));
            }
            else{
                int val = (10*(y-x))/(i-y);
                answer = min(answer,val+1);
            }
        }
        cout<<answer<<endl;
    }
}
