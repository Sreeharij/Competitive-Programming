#include <bits/stdc++.h>
using namespace std;

void func(int n){
    int counter = 0;
    int arr[n] = {0};
    bool flag = false;
    while(counter<n){
        for(int i=1;i<n+1;i++){ 
            if(arr[i-1] == 0){
                if(flag==false){
                    flag = true;
                }
                else{
                    cout<<i<<" ";
                    arr[i-1] = 1;
                    flag = false;
                    counter++;
                }
            }

        }
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    func(n);
    return 0;
}